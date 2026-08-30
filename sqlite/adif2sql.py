#!/usr/bin/env python3
"""
adif2sql.py -- fetch the current ADIF release's exported data files and turn the
enumerations into SQL for the Hammy reference bundle.

Usage:
    python3 adif2sql.py --list                  # show what the zip contains
    python3 adif2sql.py -o 07-adif.sql          # fetch, parse, emit SQL
    python3 adif2sql.py --zip local.zip --list  # work from an already-downloaded zip
    python3 adif2sql.py --version 316 -o out.sql

How the site works
------------------
  * https://adif.org.uk/adiflatestrelease.txt returns the release as three
    digits, e.g. "317" meaning ADIF 3.1.7.
  * Most filenames can be constructed from that: 317/adx317.xsd and so on.
  * The resources zip CANNOT: its name embeds a release date that is not derivable
    from the version number (ADIF_317_resources_2026_03_22.zip). So this script
    scrapes /317/index.htm to find it rather than guessing.
  * The hosting provider blocks unrecognised User-Agent strings. Python's default
    ("Python-urllib/3.x") is one of the blocked ones, so a UA is set explicitly
    below. Do not remove it.

Be polite: the ADIF site asks that applications download and keep local copies
rather than fetching on every run. This script is a build-time tool, not a
runtime dependency - run it when you cut a new bundle, commit the output.
"""

import argparse
import csv
import io
import os
import re
import sys
import urllib.error
import urllib.request
from datetime import date, timezone
import zipfile

BASE = "https://adif.org.uk"
LATEST_URL = BASE + "/adiflatestrelease.txt"

# The hosting provider blocks Python's default UA. Any plausible string works;
# this one identifies the tool honestly, which is the polite option.
USER_AGENT = "Hammy-refbundle/1.0 (+https://hammybot.org)"

RETRIEVED = date.today().isoformat()

# The resources zip ships every enumeration in six formats:
#   exports/{csv,json,ods,tsv,xlsx,xml}/enumerations_<name>.<ext>
# Only one text format is wanted. ods and xlsx are themselves zip archives and
# json/xml are not delimited, so feeding them to a CSV reader produces garbage.
FORMATS = ("tsv", "csv")

# Members are matched with an anchored pattern rather than a substring test.
# Substring matching collapsed enumerations_mode, enumerations_submode and
# enumerations_propagation_mode into one table.
def member_pattern(fmt):
    return re.compile(
        rf"(?:^|/)exports/{fmt}/enumerations_(?P<name>[A-Za-z0-9_]+)\.{fmt}$",
        re.IGNORECASE)


# Optional prettier names. Anything not listed becomes adif_<enumeration_name>.
TABLE_ALIASES = {
    "dxcc_entity_code": "adif_dxcc",
    "primary_administrative_subdivision": "adif_subdivisions",
    "secondary_administrative_subdivision": "adif_subdivisions_secondary",
    "secondary_administrative_subdivision_alt": "adif_subdivisions_secondary_alt",
}


def table_for(enum_name):
    key = enum_name.lower()

    return TABLE_ALIASES.get(key, "adif_" + key)


def fetch(url, binary=False):
    req = urllib.request.Request(url, headers={"User-Agent": USER_AGENT})
    try:
        with urllib.request.urlopen(req, timeout=60) as resp:
            data = resp.read()
    except urllib.error.HTTPError as exc:
        if exc.code == 403:
            sys.exit(f"403 from {url} - the User-Agent is being blocked. "
                     f"Current UA: {USER_AGENT!r}")
        raise

    return data if binary else data.decode("utf-8", errors="replace")


def latest_version():
    return fetch(LATEST_URL).strip()


def find_resources_zip(version):
    """Scrape the version index for the resources zip, whose name carries a date."""
    index = fetch(f"{BASE}/{version}/index.htm")

    m = re.search(rf"ADIF_{version}_resources[_\d]*\.zip", index, re.IGNORECASE)
    if not m:
        sys.exit(f"no resources zip linked from {BASE}/{version}/index.htm - "
                 f"the page layout may have changed, check it by hand")

    return f"{BASE}/{version}/{m.group(0)}"


def load_zip(path_or_url):
    if os.path.exists(path_or_url):
        return zipfile.ZipFile(path_or_url)

    return zipfile.ZipFile(io.BytesIO(fetch(path_or_url, binary=True)))


def sniff_rows(zf, name):
    """Read a member as delimited text, guessing the delimiter."""
    raw = zf.read(name).decode("utf-8-sig", errors="replace")

    # ADIF's exports ship with CRLF. io.StringIO translates newlines by default,
    # which leaves the \r attached to the last field of every row and makes csv
    # raise "new-line character seen in unquoted field". Normalise first, then
    # open with newline="" so csv does its own line splitting.
    raw = raw.replace("\r\n", "\n").replace("\r", "\n")

    first_line = raw.split("\n", 1)[0]

    # Prefer an explicit tab check over Sniffer. These files are tab-separated
    # and their description columns contain commas, which Sniffer sometimes
    # mistakes for the delimiter.
    if "\t" in first_line:
        dialect = csv.excel_tab
    else:
        try:
            dialect = csv.Sniffer().sniff(raw[:4096], delimiters="\t,;")
        except csv.Error:
            dialect = csv.excel_tab

    reader = csv.reader(io.StringIO(raw, newline=""), dialect)

    try:
        rows = [r for r in reader if any(cell.strip() for cell in r)]
    except csv.Error as exc:
        # Not a delimited file at all - a .adi test QSO file, say. Skip it
        # rather than taking the whole run down.
        sys.stderr.write(f"skipping {name}: {exc}\n")
        return [], []

    if not rows:
        return [], []

    return rows[0], rows[1:]


def ident(name):
    """Turn an arbitrary header cell into a safe SQL column name."""
    col = re.sub(r"[^0-9a-zA-Z]+", "_", name.strip().lower()).strip("_")

    return col or "col"


def q(value):
    if value is None or value == "":
        return "NULL"

    return "'" + str(value).replace("'", "''") + "'"


# Pure ADIF bookkeeping: identical on every row of every file, and recorded once
# in ref_sources instead. Everything else is kept even when constant, because a
# constant can be meaningful - adif_award.import_only is 'Import-only' on all 29
# rows, which says something real about those awards.
METADATA_COLUMNS = {"enumeration_name", "adif_version", "adif_status"}


def prune_columns(cols, rows, keep_all=False):
    """Drop ADIF bookkeeping and columns that are empty in this file.

    Returns (kept_column_names, kept_rows, dropped_report).
    """
    if keep_all:
        return cols, rows, []

    keep, dropped = [], []

    for i, c in enumerate(cols):
        values = {(r[i].strip() if i < len(r) and r[i] is not None else "") for r in rows}

        # Compare on the normalised name: headers arrive as "Enumeration Name",
        # "ADIF Version" and so on, and are only identifier-ised later.
        if ident(c) in METADATA_COLUMNS:
            sample = next(iter(values)) if len(values) == 1 else None
            dropped.append((c, f"metadata{'=' + sample if sample else ''}"))
            continue

        if values <= {""}:
            dropped.append((c, "empty"))
            continue

        keep.append(i)

    kept_cols = [cols[i] for i in keep]
    kept_rows = [[(r[i] if i < len(r) else "") for i in keep] for r in rows]

    return kept_cols, kept_rows, dropped


def emit_table(table, header, rows, out):
    cols = []
    seen = {}
    for h in header:
        c = ident(h)
        if c in seen:
            seen[c] += 1
            c = f"{c}_{seen[c]}"
        else:
            seen[c] = 0
        cols.append(c)

    out.write(f"\nDROP TABLE IF EXISTS {table};\n")
    out.write(f"CREATE TABLE {table} (\n")
    out.write(",\n".join(f"    {c} TEXT" for c in cols))
    out.write("\n);\n\n")

    out.write(f"INSERT INTO {table} ({', '.join(cols)}) VALUES\n")

    lines = []
    for r in rows:
        # Pad or trim to the header width; ADIF exports occasionally have
        # ragged trailing columns.
        r = (list(r) + [""] * len(cols))[:len(cols)]
        lines.append("    (" + ", ".join(q(cell.strip()) for cell in r) + ")")

    out.write(",\n".join(lines) + ";\n")


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--version", help="3-digit ADIF version (default: whatever is current)")
    ap.add_argument("--zip", dest="zip_path", help="use a local zip instead of downloading")
    ap.add_argument("--list", action="store_true", help="list zip contents and exit")
    ap.add_argument("-o", "--output", help="write SQL here (default: stdout)")
    ap.add_argument("--format", choices=FORMATS, default="tsv",
                    help="which export format to read (default: tsv). The zip also "
                         "contains json, xml, ods and xlsx copies, which are not "
                         "delimited text and are ignored")
    ap.add_argument("--keep-all-columns", action="store_true",
                    help="keep ADIF bookkeeping columns (enumeration_name, "
                         "adif_version, adif_status) and columns that are empty "
                         "in this release")
    ap.add_argument("--only", nargs="+", metavar="ENUM",
                    help="import just these enumerations by name, e.g. "
                         "--only mode band dxcc_entity_code")
    args = ap.parse_args()

    if args.zip_path:
        source = args.zip_path
        version = args.version or "local"
    else:
        version = args.version or latest_version()
        sys.stderr.write(f"ADIF version {version}\n")
        source = find_resources_zip(version)
        sys.stderr.write(f"resources: {source}\n")

    zf = load_zip(source)
    members = [n for n in zf.namelist() if not n.endswith("/")]

    if args.list:
        for n in sorted(members):
            info = zf.getinfo(n)
            print(f"  {info.file_size:9d}  {n}")
        print(f"\n{len(members)} files")

        return 0

    pat = member_pattern(args.format)
    only = {o.lower() for o in args.only} if args.only else None

    picked = []
    for n in members:
        m = pat.search(n)
        if not m:
            continue

        enum_name = m.group("name").lower()
        if only and enum_name not in only:
            continue

        picked.append((n, enum_name, table_for(enum_name)))

    picked.sort(key=lambda x: x[2])

    if not picked:
        sys.exit(f"no exports/{args.format}/enumerations_*.{args.format} members found. "
                 f"Run with --list to see the zip layout.")

    # One member per table, or a later file silently clobbers an earlier one.
    by_table = {}
    for n, enum_name, table in picked:
        if table in by_table:
            sys.exit(f"{table} claimed by both {by_table[table]} and {n} - "
                     f"add an entry to TABLE_ALIASES to disambiguate")
        by_table[table] = n

    out = open(args.output, "w", encoding="utf-8") if args.output else sys.stdout
    try:
        out.write("-- Generated by adif2sql.py. Do not edit by hand.\n")
        out.write(f"-- ADIF version {version}, {args.format} exports, from {source}\n")
        out.write("-- Columns are all TEXT: these are enumerations, and ADIF's own\n")
        out.write("-- exports carry version-dependent extra columns. Cast at query time.\n")

        for name, enum_name, table in picked:
            header, rows = sniff_rows(zf, name)
            if not header:
                sys.stderr.write(f"skipping empty {name}\n")
                continue

            header, rows, dropped = prune_columns(header, rows, args.keep_all_columns)

            note = f"  (-{len(dropped)} cols)" if dropped else ""
            sys.stderr.write(f"{enum_name:44} -> {table:32} {len(rows):5d} rows{note}\n")

            emit_table(table, header, rows, out)

            # Provenance, so audit.py stops complaining about undocumented tables.
            out.write(
                "\nINSERT OR REPLACE INTO ref_sources "
                "(dataset, source_name, source_url, license, retrieved, notes) VALUES\n"
                f"    ({q(table)}, {q('ADIF ' + version + ' ' + enum_name)}, "
                f"{q(source)}, 'ADIF specification, openly published', "
                f"{q(RETRIEVED)}, "
                f"{q('Generated by adif2sql.py. Dropped columns: ' + (', '.join(c for c, _ in dropped) or 'none'))});\n")
    finally:
        if args.output:
            out.close()

    return 0


if __name__ == "__main__":
    sys.exit(main())
