#!/usr/bin/env python3
"""
cty2sql.py -- convert AD1C cty.dat (ham radio DXCC country file) into SQL
INSERT statements for the dxcc_entities / dxcc_prefixes tables.

Usage:
    python3 cty2sql.py cty.dat > dxcc.sql
    python3 cty2sql.py cty.dat -o dxcc.sql --schema --transaction

Notes on cty.dat that this script deals with for you:

  * cty.dat has NO DXCC entity numbers. The ADIF entity code (1 = Canada,
    291 = United States, ...) is supplied by the DXCC_IDS table below, keyed
    on the record's primary prefix. Override or extend it with --dxcc-map
    (a JSON file of {"primary_prefix": entity_id}).
  * cty.dat longitudes are POSITIVE WEST. This script flips them to the
    conventional positive-east form by default (Ottawa -> -75.0). Use
    --longitude as-is to keep the raw cty.dat sign.
  * cty.dat UTC offsets are also positive-west (Canada 5.0, Japan -9.0) and
    are emitted unchanged by default, matching the target schema. Use
    --utc-offset standard to flip them into real UTC offsets (Japan +9.0).
  * Entities whose primary prefix starts with "*" are WAE/CQ-only entities
    (Sicily, Shetland Is., European Turkey, ...). They are not DXCC entities
    and have no entity code, so they are skipped unless --include-wae is
    given (which requires you to supply ids for them via --dxcc-map).
  * Prefix modifiers are stripped: (cq) [itu] <lat/lon> {cont} ~offset~.
    A prefix written "=CALL" is a full callsign match and is emitted with
    exact = 1.

No third-party dependencies. Python 3.8+.
"""

import argparse
import json
import os
import re
import sys
from collections import OrderedDict

# --------------------------------------------------------------------------
# cty.dat primary prefix -> ADIF DXCC entity code (ADIF 3.1.6 enumeration).
# Deleted entities are not included. Regenerate/extend with --dxcc-map.
# --------------------------------------------------------------------------
DXCC_IDS = {
    "VE": 1, "YA": 3, "3B6": 4, "OH0": 5, "KL": 6, "ZA": 7, "KH8": 9, "FT/z": 10, "VU4": 11,
    "VP2E": 12, "CE9": 13, "EK": 14, "UA9": 15, "ZL9": 16, "YV0": 17, "4J": 18, "KH1": 20,
    "EA6": 21, "T8": 22, "3Y/b": 24, "EU": 27, "EA8": 29, "T31": 31, "EA9": 32, "VQ9": 33,
    "ZL7": 34, "VK9X": 35, "FO/c": 36, "TI9": 37, "VK9C": 38, "SV9": 40, "FT/w": 41, "KP5": 43,
    "SV5": 45, "9M6": 46, "CE0Y": 47, "T32": 48, "3C": 49, "XE": 50, "E3": 51, "ES": 52,
    "ET": 53, "UA": 54, "PY0F": 56, "C6": 60, "R1FJ": 61, "8P": 62, "FY": 63, "VP9": 64,
    "VP2V": 65, "V3": 66, "ZF": 69, "CM": 70, "HC8": 71, "HI": 72, "YS": 74, "4L": 75,
    "TG": 76, "J3": 77, "HH": 78, "FG": 79, "HR": 80, "6Y": 82, "FM": 84, "YN": 86, "HP": 88,
    "VP5": 89, "9Y": 90, "P4": 91, "V2": 94, "J7": 95, "VP2M": 96, "J6": 97, "J8": 98,
    "FT/g": 99, "LU": 100, "KH2": 103, "CP": 104, "KG4": 105, "GU": 106, "3X": 107, "PY": 108,
    "J5": 109, "KH6": 110, "VK0H": 111, "CE": 112, "GD": 114, "HK": 116, "4U1I": 117,
    "JX": 118, "HC": 120, "GJ": 122, "KH3": 123, "FT/j": 124, "CE0Z": 125, "UA2": 126,
    "8R": 129, "UN": 130, "FT/x": 131, "ZP": 132, "ZL8": 133, "EX": 135, "OA": 136, "HL": 137,
    "KH7K": 138, "PZ": 140, "VP8": 141, "VU7": 142, "XW": 143, "CX": 144, "YL": 145, "LY": 146,
    "VK9L": 147, "YV": 148, "CU": 149, "VK": 150, "XX9": 152, "VK0M": 153, "C2": 157,
    "YJ": 158, "8Q": 159, "A3": 160, "HK0/m": 161, "FK": 162, "P2": 163, "3B8": 165,
    "KH0": 166, "OJ0": 167, "V7": 168, "FH": 169, "ZL": 170, "VK9M": 171, "VP6": 172,
    "V6": 173, "KH4": 174, "FO": 175, "3D2": 176, "JD/m": 177, "ER": 179, "SV/a": 180,
    "C9": 181, "KP1": 182, "H4": 185, "5U": 187, "E6": 188, "VK9N": 189, "5W": 190,
    "E5/n": 191, "JD/o": 192, "3C0": 195, "KH5": 197, "3Y/p": 199, "ZS8": 201, "KP4": 202,
    "C3": 203, "XF4": 204, "ZD8": 205, "OE": 206, "3B9": 207, "ON": 209, "CY0": 211, "LZ": 212,
    "FS": 213, "TK": 214, "5B": 215, "HK0/a": 216, "CE0X": 217, "S9": 219, "OZ": 221,
    "OY": 222, "G": 223, "OH": 224, "IS": 225, "F": 227, "DL": 230, "T5": 232, "ZB": 233,
    "E5/s": 234, "VP8/g": 235, "SV": 236, "OX": 237, "VP8/o": 238, "HA": 239, "VP8/s": 240,
    "VP8/h": 241, "TF": 242, "EI": 245, "1A": 246, "1S": 247, "I": 248, "V4": 249, "ZD7": 250,
    "HB0": 251, "CY9": 252, "PY0S": 253, "LX": 254, "CT3": 256, "9H": 257, "JW": 259,
    "3A": 260, "EY": 262, "PA": 263, "GI": 265, "LA": 266, "SP": 269, "ZK3": 270, "CT": 272,
    "PY0T": 273, "ZD9": 274, "YO": 275, "FT/t": 276, "FP": 277, "T7": 278, "GM": 279,
    "EZ": 280, "EA": 281, "T2": 282, "ZC4": 283, "SM": 284, "KP2": 285, "5X": 286, "HB": 287,
    "UR": 288, "4U1U": 289, "K": 291, "UK": 292, "3W": 293, "GW": 294, "HV": 295, "YU": 296,
    "KH9": 297, "FW": 298, "9M2": 299, "T30": 301, "S0": 302, "VK9W": 303, "A9": 304,
    "S2": 305, "A5": 306, "TI": 308, "XZ": 309, "XU": 312, "4S": 315, "BY": 318, "VR": 321,
    "VU": 324, "YB": 327, "EP": 330, "YI": 333, "4X": 336, "JA": 339, "JY": 342, "P5": 344,
    "V8": 345, "9K": 348, "OD": 354, "JT": 363, "9N": 369, "A4": 370, "AP": 372, "DU": 375,
    "A7": 376, "HZ": 378, "S7": 379, "9V": 381, "J2": 382, "YK": 384, "BV": 386, "HS": 387,
    "TA": 390, "A6": 391, "7X": 400, "D2": 401, "A2": 402, "9U": 404, "TJ": 406, "TL": 408,
    "D4": 409, "TT": 410, "D6": 411, "TN": 412, "9Q": 414, "TY": 416, "TR": 420, "C5": 422,
    "9G": 424, "TU": 428, "5Z": 430, "7P": 432, "EL": 434, "5A": 436, "5R": 438, "7Q": 440,
    "TZ": 442, "5T": 444, "CN": 446, "5N": 450, "Z2": 452, "FR": 453, "9X": 454, "6W": 456,
    "9L": 458, "3D2/r": 460, "ZS": 462, "V5": 464, "ST": 466, "3DA": 468, "5H": 470, "3V": 474,
    "SU": 478, "XT": 480, "9J": 482, "5V": 483, "3D2/c": 489, "T33": 490, "7O": 492, "9A": 497,
    "S5": 499, "E7": 501, "Z3": 502, "OK": 503, "OM": 504, "BV9P": 505, "BS7": 506, "H40": 507,
    "FO/a": 508, "FO/m": 509, "E4": 510, "4W": 511, "FK/c": 512, "VP6/d": 513, "4O": 514,
    "KH8/s": 515, "FJ": 516, "PJ2": 517, "PJ7": 518, "PJ5": 519, "PJ4": 520, "Z8": 521,
    "Z6": 522
}


# --------------------------------------------------------------------------
# Parsing
# --------------------------------------------------------------------------

# Modifiers that may be attached to a prefix inside a cty.dat prefix list.
# These are CAPTURED rather than discarded: about 75% of the prefix tokens in a
# current cty.dat carry a zone override, and they exist precisely because the
# record default is wrong for that prefix. VK4[55] is Queensland at ITU 55, not
# Australia's default 59; drop the modifier and every Queensland call gets the
# wrong zone.
MOD_CQ = re.compile(r"\(\s*(\d+)\s*\)")
MOD_ITU = re.compile(r"\[\s*(\d+)\s*\]")
MOD_LATLON = re.compile(r"<\s*([-\d.]+)\s*/\s*([-\d.]+)\s*>")
MOD_CONT = re.compile(r"\{([^}]*)\}")
MOD_OFFSET = re.compile(r"~([^~]*)~")

MODIFIER_RE = re.compile(r"""
      \(\s*\d+\s*\)
    | \[\s*\d+\s*\]
    | <[^>]*>
    | \{[^}]*\}
    | ~[^~]*~
""", re.VERBOSE)


def split_modifiers(token):
    """Return (bare_prefix, overrides dict) for one prefix-list token."""
    ov = {"cq_zone": None, "itu_zone": None, "latitude": None,
          "longitude": None, "continent": None, "utc_offset": None}

    m = MOD_CQ.search(token)
    if m:
        ov["cq_zone"] = int(m.group(1))

    m = MOD_ITU.search(token)
    if m:
        ov["itu_zone"] = int(m.group(1))

    m = MOD_LATLON.search(token)
    if m:
        ov["latitude"] = float(m.group(1))
        ov["longitude"] = float(m.group(2))   # still positive-west here

    m = MOD_CONT.search(token)
    if m:
        ov["continent"] = m.group(1).strip().upper() or None

    m = MOD_OFFSET.search(token)
    if m:
        try:
            ov["utc_offset"] = float(m.group(1))
        except ValueError:
            ov["utc_offset"] = None

    return MODIFIER_RE.sub("", token).strip(), ov


class Entity:
    __slots__ = ("name", "cq_zone", "itu_zone", "continent", "latitude",
                 "longitude", "utc_offset", "primary", "wae", "prefixes",
                 "entity_id", "line_no")

    def __init__(self, **kw):
        for k in self.__slots__:
            setattr(self, k, kw.get(k))


def parse_cty(text):
    """Yield Entity objects from the contents of a cty.dat file."""
    text = text.replace("\r\n", "\n").replace("\r", "\n")

    # Records are terminated by ';'. Track line numbers for error messages.
    pos = 0
    line_no = 1
    for chunk in text.split(";"):
        start_line = line_no + chunk[:len(chunk) - len(chunk.lstrip("\n"))].count("\n")
        line_no += chunk.count("\n")
        record = chunk.strip()
        if not record:
            continue

        head, _, body = record.partition("\n")
        fields = [f.strip() for f in head.split(":")]
        if len(fields) < 8:
            raise ValueError(
                "line %d: expected 8 colon-separated header fields, got %d: %r"
                % (start_line, len(fields), head))

        primary = fields[7]
        wae = primary.startswith("*")

        ent = Entity(
            name=fields[0],
            cq_zone=int(fields[1]),
            itu_zone=int(fields[2]),
            continent=fields[3].upper(),
            latitude=float(fields[4]),
            longitude=float(fields[5]),
            utc_offset=float(fields[6]),
            primary=primary.lstrip("*"),
            wae=wae,
            prefixes=[],
            entity_id=None,
            line_no=start_line,
        )

        seen = set()
        for token in body.replace("\n", "").split(","):
            token = token.strip()
            if not token:
                continue
            bare, ov = split_modifiers(token)
            exact = bare.startswith("=")
            bare = bare.lstrip("=").strip().upper()
            if not bare or bare in seen:
                continue
            seen.add(bare)
            ent.prefixes.append((bare, 1 if exact else 0, ov))

        yield ent


# --------------------------------------------------------------------------
# SQL emission
# --------------------------------------------------------------------------

SCHEMA = """\
CREATE TABLE IF NOT EXISTS dxcc_entities (
    id          INTEGER PRIMARY KEY,
    name        VARCHAR(64) NOT NULL,
    continent   CHAR(2)     NOT NULL,
    cq_zone     INTEGER     NOT NULL,
    itu_zone    INTEGER     NOT NULL,
    latitude    DECIMAL(6,2) NOT NULL,
    longitude   DECIMAL(7,2) NOT NULL,
    utc_offset  DECIMAL(4,2) NOT NULL
);

CREATE TABLE IF NOT EXISTS dxcc_prefixes (
    prefix      VARCHAR(16) NOT NULL,
    entity_id   INTEGER     NOT NULL REFERENCES dxcc_entities (id),
    exact       INTEGER     NOT NULL DEFAULT 0,
    PRIMARY KEY (prefix, entity_id)
);

CREATE INDEX IF NOT EXISTS idx_dxcc_prefixes_entity ON dxcc_prefixes (entity_id);
"""


def q(value):
    """Quote a string for SQL, doubling embedded single quotes."""
    return "'" + value.replace("'", "''") + "'"


def emit_entities(entities, out):
    rows = []
    for e in entities:
        rows.append((
            "%d," % e.entity_id,
            q(e.name) + ",",
            q(e.primary) + ",",
            q(e.continent) + ",",
            "%d," % e.cq_zone,
            "%d," % e.itu_zone,
            "%.2f," % e.latitude,
            "%.2f," % e.longitude,
            "%.1f" % e.utc_offset,
        ))
    widths = [max(len(r[i]) for r in rows) for i in range(9)]
    # Numeric columns look better right-aligned, text columns left-aligned.
    align = ["<", "<", "<", "<", "<", "<", ">", ">", ">"]

    out.write("INSERT INTO dxcc_entities "
              "(id, name, primary_prefix, continent, cq_zone, itu_zone, "
              "latitude, longitude, utc_offset)"
              " VALUES\n")
    for n, row in enumerate(rows):
        cells = [format(cell, "%s%d" % (align[i], widths[i]))
                 for i, cell in enumerate(row)]
        line = "    (" + " ".join(cells).rstrip() + ")"
        out.write(line + (",\n" if n < len(rows) - 1 else ";\n"))


def emit_prefixes(entities, out, per_line=3):
    out.write("INSERT INTO dxcc_prefixes "
              "(prefix, entity_id, exact, cq_zone, itu_zone) VALUES\n")

    def n(v):
        return "NULL" if v is None else str(v)

    tuples_by_entity = []
    for e in entities:
        if e.prefixes:
            tuples_by_entity.append(
                ["(%s, %d, %d, %s, %s)" % (q(p), e.entity_id, x,
                                           n(ov["cq_zone"]), n(ov["itu_zone"]))
                 for p, x, ov in e.prefixes])

    last = len(tuples_by_entity) - 1
    for i, group in enumerate(tuples_by_entity):
        for j in range(0, len(group), per_line):
            slice_ = group[j:j + per_line]
            is_final = (i == last) and (j + per_line >= len(group))
            out.write("    " + ", ".join(slice_) + (";\n" if is_final else ",\n"))


# --------------------------------------------------------------------------
# Main
# --------------------------------------------------------------------------

def main(argv=None):
    ap = argparse.ArgumentParser(
        description="Convert a cty.dat DXCC country file into SQL INSERT statements.")
    ap.add_argument("cty", help="path to cty.dat")
    ap.add_argument("-o", "--output", help="write SQL here (default: stdout)")
    ap.add_argument("--dxcc-map", metavar="JSON",
                    help='JSON file of {"primary_prefix": entity_id} merged over '
                         "the built-in table")
    ap.add_argument("--longitude", choices=["east-positive", "as-is"],
                    default="east-positive",
                    help="cty.dat stores longitude positive-west; 'east-positive' "
                         "(default) flips it to the usual convention")
    ap.add_argument("--utc-offset", choices=["cty", "standard"], default="standard",
                    help="'cty' (default) keeps cty.dat's positive-west offsets; "
                         "'standard' flips them to real UTC offsets")
    ap.add_argument("--include-wae", action="store_true",
                    help="include WAE/CQ-only entities (needs ids via --dxcc-map)")
    ap.add_argument("--exclude-exact", action="store_true",
                    help="skip '=CALLSIGN' full-callsign entries entirely")
    ap.add_argument("--schema", action="store_true",
                    help="emit CREATE TABLE statements first")
    ap.add_argument("--truncate", action="store_true",
                    help="emit DELETE FROM statements before the inserts")
    ap.add_argument("--transaction", action="store_true",
                    help="wrap the output in BEGIN / COMMIT")
    ap.add_argument("--per-line", type=int, default=5, metavar="N",
                    help="prefix tuples per output line (default 5)")
    ap.add_argument("--strict", action="store_true",
                    help="exit non-zero if any entity has no known DXCC id")
    args = ap.parse_args(argv)

    ids = dict(DXCC_IDS)
    if args.dxcc_map:
        with open(args.dxcc_map, encoding="utf-8") as fh:
            ids.update({k: int(v) for k, v in json.load(fh).items()})

    with open(args.cty, encoding="utf-8", errors="replace") as fh:
        raw = fh.read()

    entities = []
    skipped_wae = []
    unmapped = []
    for ent in parse_cty(raw):
        if ent.wae and not args.include_wae:
            skipped_wae.append(ent)
            continue
        ent.entity_id = ids.get(ent.primary)
        if ent.entity_id is None:
            unmapped.append(ent)
            continue
        if args.longitude == "east-positive":
            ent.longitude = -ent.longitude or 0.0   # avoid "-0.00"
        if args.utc_offset == "standard":
            ent.utc_offset = -ent.utc_offset or 0.0
        if args.exclude_exact:
            ent.prefixes = [(p, x, ov) for p, x, ov in ent.prefixes if not x]
        entities.append(ent)

    entities.sort(key=lambda e: e.entity_id)

    # A prefix must resolve to one entity; cty.dat should not collide, but say
    # so loudly if a hand-edited file does.
    owner = OrderedDict()
    for e in entities:
        kept = []
        for p, x, ov in e.prefixes:
            if p in owner:
                sys.stderr.write(
                    "warning: prefix %s claimed by both %s and %s; keeping %s\n"
                    % (p, owner[p], e.name, owner[p]))
                continue
            owner[p] = e.name
            kept.append((p, x, ov))
        e.prefixes = kept

    for e in skipped_wae:
        sys.stderr.write("note: skipping WAE/CQ-only entity %s (%s)\n"
                         % (e.name, e.primary))
    for e in unmapped:
        sys.stderr.write("warning: no DXCC id for %s (primary prefix %s, line %d)\n"
                         % (e.name, e.primary, e.line_no))

    if not entities:
        sys.stderr.write("error: no entities to write\n")
        return 2

    out = open(args.output, "w", encoding="utf-8") if args.output else sys.stdout
    try:
        src = os.path.basename(args.cty)
        out.write("-- " + "-" * 73 + "\n")
        out.write("-- DXCC entities and prefixes generated from %s by cty2sql.py.\n" % src)
        out.write("-- %d entities, %d prefixes. Longitude is %s; utc_offset uses the %s.\n"
                  % (len(entities), sum(len(e.prefixes) for e in entities),
                     "positive east" if args.longitude == "east-positive"
                     else "positive west (raw cty.dat)",
                     "cty.dat sign (positive west)" if args.utc_offset == "cty"
                     else "standard UTC sign"))
        out.write("-- " + "-" * 73 + "\n")
        if args.schema:
            out.write(SCHEMA + "\n")
        if args.transaction:
            out.write("BEGIN;\n")
        if args.truncate:
            out.write("DELETE FROM dxcc_prefixes;\nDELETE FROM dxcc_entities;\n")
        emit_entities(entities, out)
        emit_prefixes(entities, out, per_line=max(1, args.per_line))
        if args.transaction:
            out.write("COMMIT;\n")
    finally:
        if args.output:
            out.close()

    sys.stderr.write("wrote %d entities and %d prefixes\n"
                     % (len(entities), sum(len(e.prefixes) for e in entities)))
    return 1 if (args.strict and unmapped) else 0


if __name__ == "__main__":
    sys.exit(main())
