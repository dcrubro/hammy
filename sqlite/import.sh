#!/usr/bin/env bash
#
# Build the Hammy reference bundle from the numbered SQL sources.
#
# The plain `for f in *.sql; do sqlite3 db < $f; done` loop keeps going after a
# failure, so one bad file leaves a half-populated database that looks fine
# until something queries the missing rows. -bail plus set -e stops at the first
# error instead.

set -euo pipefail

DB="${1:-hammy-ref.sqlite}"

# -batch ignores ~/.sqliterc, so output formatting does not depend on whatever
# .mode the developer has configured.
SQLITE=(sqlite3 -bail -batch)

# Order matters: 05-dxcc.sql must load before 06-eng-beacons.sql, because
# ncdxf_beacons.dxcc_id has a foreign key into dxcc_entities.
SOURCES=(*.sql)

if [ -e "$DB" ]; then
    echo "removing existing $DB"
    rm -f "$DB"
fi

for f in "${SOURCES[@]}"; do
    printf '  %-24s' "$f"
    "${SQLITE[@]}" "$DB" < "$f"
    echo "ok"
done

echo
echo "integrity"
fk=$("${SQLITE[@]}" "$DB" 'PRAGMA foreign_key_check;')
if [ -n "$fk" ]; then
    echo "  FOREIGN KEY VIOLATIONS:"
    echo "$fk" | sed 's/^/    /'
    exit 1
fi
echo "  foreign keys  ok"
echo "  integrity     $("${SQLITE[@]}" "$DB" 'PRAGMA integrity_check;')"

echo
echo "row counts"
# pragma_table_info returns one row per COLUMN, so counting it gives column
# counts. Real row counts need a query per table; generate them and pipe back in.
"${SQLITE[@]}" -noheader "$DB" "
    SELECT 'SELECT ''  ' || name || ''' , COUNT(*) FROM ' || name || ';'
    FROM sqlite_master WHERE type='table' ORDER BY name;
" | "${SQLITE[@]}" -noheader -separator '  ' "$DB" | awk '{printf "  %-34s %8s\n", $1, $2}'

echo
echo "compacting"
"${SQLITE[@]}" "$DB" 'VACUUM;'

ls -lh "$DB"
