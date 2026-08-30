#!/usr/bin/env python3
"""
audit.py -- consistency checks for the Hammy reference bundle.

Usage:
    python3 audit.py hammy-ref.sqlite              # run every check
    python3 audit.py hammy-ref.sqlite --quiet      # only failures
    python3 audit.py hammy-ref.sqlite --indexes    # emit CREATE INDEX DDL

Exits non-zero if any check fails, so it drops straight into CI.

The checks fall into three groups:

  structural   SQLite's own integrity and declared foreign keys.
  relational   Joins that SHOULD hold but are not declared as foreign keys,
               mostly because the ADIF tables are generated with TEXT columns.
               Orphans here mean two datasets disagree.
  domain       Amateur-radio specific invariants. Band edges that cross, gaps in
               the beacon cycle, prefixes that resolve to nothing. These are the
               ones that catch a bad hand-entered row.
"""

import argparse
import sqlite3
import sys

FAILURES = []
WARNINGS = []


def fail(check, detail):
    FAILURES.append((check, detail))


def warn(check, detail):
    WARNINGS.append((check, detail))


def tables(db):
    return [r[0] for r in db.execute(
        "SELECT name FROM sqlite_master WHERE type='table' "
        "AND name NOT LIKE 'sqlite_%' ORDER BY name")]


def columns(db, table):
    return [r[1] for r in db.execute(f"PRAGMA table_info({table})")]


def indexed_columns(db, table):
    """Columns usable as the LEADING column of some index or the primary key.

    In a composite key (prefix, entity_id) only 'prefix' is reachable; a query
    filtering on entity_id alone still scans. PRAGMA table_info's pk field is
    the 1-based position within the key, so pk == 1 is the leading column.
    """
    covered = set()

    for row in db.execute(f"PRAGMA table_info({table})"):
        if row[5] == 1:
            covered.add(row[1])

    for idx in db.execute(f"PRAGMA index_list({table})"):
        info = list(db.execute(f"PRAGMA index_info({idx[1]})"))
        if info:
            covered.add(info[0][2])

    return covered


# ---------------------------------------------------------------------------
# Structural
# ---------------------------------------------------------------------------

def check_structural(db, verbose):
    result = db.execute("PRAGMA integrity_check").fetchone()[0]
    if result != "ok":
        fail("integrity_check", result)
    elif verbose:
        print("  integrity_check                  ok")

    violations = db.execute("PRAGMA foreign_key_check").fetchall()
    if violations:
        for v in violations[:10]:
            fail("foreign_key_check", f"{v[0]} rowid {v[1]} -> {v[2]}")
    elif verbose:
        print("  foreign_key_check                ok")


# ---------------------------------------------------------------------------
# Relational: undeclared joins that should still hold
# ---------------------------------------------------------------------------

# (child table, child column, parent table, parent column, description)
RELATIONS = [
    ("dxcc_prefixes", "entity_id", "dxcc_entities", "id",
     "every prefix resolves to an entity"),
    ("band_segments", "band_id", "bands", "id",
     "every segment belongs to a band"),
    ("band_segments", "class_id", "license_classes", "id",
     "every segment's licence class exists"),
    ("ncdxf_beacons", "dxcc_id", "dxcc_entities", "id",
     "beacon entities resolve"),
    ("ncdxf_frequencies", "band_id", "bands", "id",
     "beacon frequencies map to a band"),
    # ADIF tables are all TEXT, so these need a CAST to join against integers.
    ("adif_subdivisions", "dxcc_entity_code", "adif_dxcc", "entity_code",
     "subdivisions point at a real ADIF entity"),
]


def check_relations(db, verbose):
    present = set(tables(db))

    for child, ccol, parent, pcol, desc in RELATIONS:
        if child not in present or parent not in present:
            continue
        if ccol not in columns(db, child) or pcol not in columns(db, parent):
            warn(f"{child}.{ccol}", f"column missing, skipped ({desc})")
            continue

        # TRIM both sides: the ADIF exports pad some cells.
        q = (f"SELECT COUNT(*) FROM {child} c "
             f"WHERE c.{ccol} IS NOT NULL AND TRIM(c.{ccol}) <> '' "
             f"AND NOT EXISTS (SELECT 1 FROM {parent} p "
             f"                WHERE TRIM(p.{pcol}) = TRIM(c.{ccol}))")
        orphans = db.execute(q).fetchone()[0]

        if orphans:
            sample = db.execute(
                f"SELECT DISTINCT c.{ccol} FROM {child} c "
                f"WHERE NOT EXISTS (SELECT 1 FROM {parent} p "
                f"WHERE TRIM(p.{pcol}) = TRIM(c.{ccol})) "
                f"AND TRIM(c.{ccol}) <> '' LIMIT 5").fetchall()
            vals = ", ".join(repr(s[0]) for s in sample)
            fail(f"{child}.{ccol} -> {parent}.{pcol}",
                 f"{orphans} orphan rows ({desc}); e.g. {vals}")
        elif verbose:
            print(f"  {child}.{ccol} -> {parent}.{pcol}".ljust(66) + "ok")


# ---------------------------------------------------------------------------
# Domain invariants
# ---------------------------------------------------------------------------

def check_domain(db, verbose):
    present = set(tables(db))

    def q1(sql, *args):
        return db.execute(sql, args).fetchone()[0]

    if "band_segments" in present:
        n = q1("SELECT COUNT(*) FROM band_segments WHERE low_hz >= high_hz")
        if n:
            fail("band_segments", f"{n} rows where low_hz >= high_hz")
        elif verbose:
            print("  band_segments edges ordered".ljust(66) + "ok")

        # A segment outside its own band's extent is almost always a typo.
        rows = db.execute("""
            SELECT b.name, s.low_hz, s.high_hz, b.edge_low_hz, b.edge_high_hz
            FROM band_segments s JOIN bands b ON b.id = s.band_id
            WHERE s.low_hz < b.edge_low_hz OR s.high_hz > b.edge_high_hz""").fetchall()
        if rows:
            for r in rows[:5]:
                fail("band_segments", f"{r[0]} segment {r[1]}-{r[2]} outside band {r[3]}-{r[4]}")
        elif verbose:
            print("  band_segments within band edges".ljust(66) + "ok")

        # Two segments for the same country+region+class+mode should not overlap.
        # iaru_region must be part of the key: the Region 1 and Region 3
        # allocation rows share country='' and legitimately cover the same
        # frequencies.
        rows = db.execute("""
            SELECT a.country, a.iaru_region, a.class_id, a.modes,
                   a.low_hz, a.high_hz, b.low_hz, b.high_hz
            FROM band_segments a JOIN band_segments b
              ON a.id < b.id AND a.country = b.country
             AND IFNULL(a.iaru_region,-1) = IFNULL(b.iaru_region,-1)
             AND IFNULL(a.class_id,-1) = IFNULL(b.class_id,-1)
             AND a.modes = b.modes
             AND a.low_hz < b.high_hz AND b.low_hz < a.high_hz""").fetchall()
        if rows:
            for r in rows[:5]:
                warn("band_segments", f"{r[0] or 'IARU R' + str(r[1])} class {r[2]} {r[3]}: "
                                      f"{r[4]}-{r[5]} overlaps {r[6]}-{r[7]}")
        elif verbose:
            print("  band_segments no overlaps".ljust(66) + "ok")

    if "ncdxf_beacons" in present:
        slots = [r[0] for r in db.execute("SELECT slot_index FROM ncdxf_beacons ORDER BY slot_index")]
        if slots != list(range(18)):
            fail("ncdxf_beacons", f"expected slots 0..17, got {len(slots)}: {slots}")
        elif verbose:
            print("  ncdxf_beacons slots 0..17 complete".ljust(66) + "ok")

    if "dxcc_prefixes" in present:
        # Longest-prefix matching breaks if a prefix is empty or has whitespace.
        n = q1("SELECT COUNT(*) FROM dxcc_prefixes WHERE prefix IS NULL OR TRIM(prefix) <> prefix OR prefix = ''")
        if n:
            fail("dxcc_prefixes", f"{n} prefixes empty or with surrounding whitespace")
        elif verbose:
            print("  dxcc_prefixes clean".ljust(66) + "ok")

        # Zone overrides that merely restate the entity default are noise.
        n = q1("""SELECT COUNT(*) FROM dxcc_prefixes p JOIN dxcc_entities e ON e.id = p.entity_id
                  WHERE p.cq_zone = e.cq_zone AND p.itu_zone = e.itu_zone""")
        if n:
            warn("dxcc_prefixes", f"{n} rows whose zone override equals the entity default")

    if "morse" in present:
        n = q1("SELECT COUNT(*) FROM (SELECT code FROM morse GROUP BY code HAVING COUNT(*) > 1)")
        if n:
            fail("morse", f"{n} duplicate codes - decoding would be ambiguous")
        elif verbose:
            print("  morse codes unique".ljust(66) + "ok")

    if "ref_sources" in present:
        # Every populated table should say where it came from.
        documented = {r[0] for r in db.execute("SELECT dataset FROM ref_sources")}
        undocumented = []
        for t in tables(db):
            if t.startswith(("ref_", "sqlite_")):
                continue
            if q1(f"SELECT COUNT(*) FROM {t}") == 0:
                continue
            if t not in documented and not any(d in t or t in d for d in documented):
                undocumented.append(t)
        if undocumented:
            warn("ref_sources", f"no provenance row for: {', '.join(undocumented)}")
        elif verbose:
            print("  ref_sources covers every table".ljust(66) + "ok")


# ---------------------------------------------------------------------------
# Dead weight
# ---------------------------------------------------------------------------

def check_dead_columns(db, verbose, group=True):
    """Constant or empty columns.

    A constant column is not automatically a bug: adif_award.import_only is
    'Import-only' on every row because every award in that enumeration is, and
    adif_subdivisions_secondary.dxcc_entity_code is '6' because Alaska is the
    only entity with secondary subdivisions. Empty columns are always dead
    weight. Both are reported, but repeated findings across many tables collapse
    into one line so the signal is not buried.
    """
    empties = []
    constants = []

    for t in tables(db):
        total = db.execute(f"SELECT COUNT(*) FROM {t}").fetchone()[0]
        if total < 2:
            continue

        for c in columns(db, t):
            distinct = db.execute(
                f'SELECT COUNT(DISTINCT IFNULL("{c}", char(0))) FROM "{t}"').fetchone()[0]

            if distinct != 1:
                continue

            val = db.execute(f'SELECT "{c}" FROM "{t}" LIMIT 1').fetchone()[0]

            if val is None or str(val).strip() == "":
                empties.append((t, c, total))
            else:
                constants.append((t, c, val, total))

    if group:
        # Collapse by column name: the same finding across 20 ADIF tables is one
        # fact about the export format, not 20 problems.
        by_col = {}
        for t, c, total in empties:
            by_col.setdefault(c, []).append(t)
        for c, ts in sorted(by_col.items()):
            if len(ts) > 2:
                warn(f"*.{c}", f"entirely empty in {len(ts)} tables - drop it "
                               f"({', '.join(ts[:3])}, ...)")
            else:
                for t in ts:
                    warn(f"{t}.{c}", "entirely empty - drop it")

        by_col = {}
        for t, c, val, total in constants:
            by_col.setdefault((c, str(val)), []).append(t)
        for (c, val), ts in sorted(by_col.items()):
            if len(ts) > 2:
                warn(f"*.{c}", f"constant {val!r} in {len(ts)} tables - redundant "
                               f"({', '.join(ts[:3])}, ...)")
            else:
                for t in ts:
                    warn(f"{t}.{c}", f"constant {val!r} - check it is meaningful")
    else:
        for t, c, total in empties:
            warn(f"{t}.{c}", f"entirely empty across {total} rows - drop it")
        for t, c, val, total in constants:
            warn(f"{t}.{c}", f"constant {val!r} across {total} rows - redundant")


def check_duplicates(db, verbose):
    """Exact duplicate rows, which in a reference table are always a mistake."""
    for t in tables(db):
        cols = columns(db, t)
        if not cols:
            continue

        collist = ", ".join(f'"{c}"' for c in cols)
        n = db.execute(
            f"SELECT COUNT(*) FROM (SELECT {collist}, COUNT(*) AS n "
            f'FROM "{t}" GROUP BY {collist} HAVING n > 1)').fetchone()[0]

        if n:
            warn(t, f"{n} groups of exactly duplicated rows")
        elif verbose:
            print(f"  {t} no duplicate rows".ljust(66) + "ok")


# ---------------------------------------------------------------------------
# Index generation
# ---------------------------------------------------------------------------

# Columns worth indexing, by suffix or exact name.
#
# An index only helps a query that filters with equality or a range on its
# leading column. It does NOT help "? GLOB prefix || '*'", because the indexed
# column is on the wrong side of the comparison - SQLite still scans every row
# and evaluates the GLOB. Worse, an index can make such a query slower by
# tempting the planner into a nested loop.
#
# The fix for callsign lookup is on the query side, not here: generate the
# candidate prefixes from the callsign and do equality seeks, longest first.
# See docs in the repo. That turns a 7000-row scan into a handful of index
# seeks, measured at roughly 40x on the current bundle.
INDEX_HINTS = ("code", "_code", "_id", "name", "prefix", "callsign", "band",
               "mode", "abbr", "symbol", "letter", "character", "grid",
               "country", "continent", "cq_zone", "itu_zone", "dataset")


def emit_indexes(db, out):
    out.write("-- Generated by audit.py --indexes. Runs last in the build.\n")
    out.write("-- The bundle is read-only, so indexes cost file size and nothing else.\n\n")

    # Indexes the heuristic cannot infer but the bot's hot paths need.
    ESSENTIAL = [
        ("dxcc_prefixes", "prefix",
         "candidate-prefix equality lookup; leading PK column, but stated "
         "explicitly because everything depends on it"),
        ("dxcc_prefixes", "entity_id", "joins back to dxcc_entities"),
    ]

    made = 0
    present = set(tables(db))
    for t, c, why in ESSENTIAL:
        if t in present and c in columns(db, t):
            out.write(f"-- {why}\n")
            out.write(f'CREATE INDEX IF NOT EXISTS idx_{t}_{c} ON "{t}" ("{c}");\n')
            made += 1
    out.write("\n")

    for t in tables(db):
        if t.startswith("ref_"):
            continue

        total = db.execute(f"SELECT COUNT(*) FROM {t}").fetchone()[0]
        if total < 50:      # a scan of 50 rows is free
            continue

        covered = indexed_columns(db, t)

        for c in columns(db, t):
            if c in covered or (t, c) in {(a, b) for a, b, _ in ESSENTIAL}:
                continue

            lc = c.lower()
            if not (lc in INDEX_HINTS or any(lc.endswith(h) for h in INDEX_HINTS)):
                continue

            # A column with almost no distinct values is not worth an index.
            distinct = db.execute(f'SELECT COUNT(DISTINCT "{c}") FROM "{t}"').fetchone()[0]
            if distinct < 2 or distinct < total / 100:
                continue

            out.write(f'CREATE INDEX IF NOT EXISTS idx_{t}_{lc} ON "{t}" ("{c}");\n')
            made += 1

        out.write("\n")

    out.write("ANALYZE;\n")
    sys.stderr.write(f"{made} indexes\n")


# ---------------------------------------------------------------------------

def main():
    ap = argparse.ArgumentParser(description="Audit the Hammy reference bundle")
    ap.add_argument("db", help="path to the bundle")
    ap.add_argument("--quiet", action="store_true", help="only report problems")
    ap.add_argument("--ungrouped", action="store_true",
                    help="report every constant/empty column separately instead of "
                         "collapsing repeated findings")
    ap.add_argument("--indexes", action="store_true",
                    help="emit CREATE INDEX DDL to stdout instead of auditing")
    ap.add_argument("-o", "--output", help="write index DDL here")
    args = ap.parse_args()

    db = sqlite3.connect(f"file:{args.db}?mode=ro", uri=True)
    db.execute("PRAGMA foreign_keys = ON")

    if args.indexes:
        out = open(args.output, "w") if args.output else sys.stdout
        try:
            emit_indexes(db, out)
        finally:
            if args.output:
                out.close()

        return 0

    verbose = not args.quiet

    if verbose:
        print("structural")
    check_structural(db, verbose)

    if verbose:
        print("\nrelational")
    check_relations(db, verbose)

    if verbose:
        print("\ndomain")
    check_domain(db, verbose)

    if verbose:
        print("\ndead weight and duplicates")
    check_dead_columns(db, verbose, group=not args.ungrouped)
    check_duplicates(db, False)

    print()
    for check, detail in WARNINGS:
        print(f"WARN  {check}: {detail}")
    for check, detail in FAILURES:
        print(f"FAIL  {check}: {detail}")

    print(f"\n{len(FAILURES)} failures, {len(WARNINGS)} warnings")

    return 1 if FAILURES else 0


if __name__ == "__main__":
    sys.exit(main())
