-- Hammy reference bundle schema
--
-- Read-only at runtime. Regenerated as a whole file, never migrated in place.
-- Open with SQLITE_OPEN_READONLY.

PRAGMA foreign_keys = ON;

-- ---------------------------------------------------------------------------
-- Bundle metadata
-- ---------------------------------------------------------------------------

CREATE TABLE ref_meta (
    key         TEXT PRIMARY KEY,
    value       TEXT NOT NULL
);

-- Where each dataset came from and when. Shown by /about and used to decide
-- whether a newer bundle is worth downloading.
CREATE TABLE ref_sources (
    dataset     TEXT PRIMARY KEY,
    source_name TEXT NOT NULL,
    source_url  TEXT,
    license     TEXT,
    retrieved   TEXT,          -- ISO 8601 date
    notes       TEXT
);

-- ---------------------------------------------------------------------------
-- Bands and privileges
-- ---------------------------------------------------------------------------

-- Named bands, region-independent. edge_low/high are the widest extent across
-- all regions; per-region reality lives in band_segments.
CREATE TABLE bands (
    id          INTEGER PRIMARY KEY,
    name        TEXT NOT NULL UNIQUE,   -- '20m', '70cm'
    edge_low_hz INTEGER NOT NULL,
    edge_high_hz INTEGER NOT NULL,
    wavelength_m REAL,
    sort_order  INTEGER NOT NULL
);

CREATE TABLE license_classes (
    id          INTEGER PRIMARY KEY,
    country     TEXT NOT NULL,          -- ISO 3166-1 alpha-2
    code        TEXT NOT NULL,          -- 'E', 'G', 'T'
    name        TEXT NOT NULL,
    rank        INTEGER NOT NULL,       -- higher = more privileges
    notes       TEXT,
    UNIQUE (country, code)
);

-- One row per (country, class, contiguous frequency range, mode group).
-- A class with split phone/CW privileges on a band gets several rows.
CREATE TABLE band_segments (
    id          INTEGER PRIMARY KEY,
    band_id     INTEGER NOT NULL REFERENCES bands(id),
    country     TEXT NOT NULL,
    iaru_region INTEGER,                -- 1, 2, 3, or NULL if not region-scoped
    class_id    INTEGER REFERENCES license_classes(id),
    low_hz      INTEGER NOT NULL,
    high_hz     INTEGER NOT NULL,
    modes       TEXT NOT NULL,          -- 'CW', 'CW,DATA', 'PHONE,IMAGE'
    max_power_w INTEGER,                -- NULL = national default
    notes       TEXT
);

CREATE INDEX idx_band_segments_freq ON band_segments (country, low_hz, high_hz);
CREATE INDEX idx_band_segments_class ON band_segments (class_id);

-- ---------------------------------------------------------------------------
-- DXCC
-- ---------------------------------------------------------------------------

-- id is the ADIF/ARRL DXCC entity code, supplied by cty2sql.py's DXCC_IDS map
-- (cty.dat itself carries no entity numbers). WAE and other non-DXCC entities
-- are excluded by default since they have no code.
--
-- latitude is north-positive and longitude is east-positive; utc_offset is the
-- usual "UTC + this = local". All three are flipped relative to cty.dat's own
-- positive-west conventions by the importer.
CREATE TABLE dxcc_entities (
    id             INTEGER PRIMARY KEY,   -- ADIF DXCC entity code
    name           TEXT NOT NULL,
    primary_prefix TEXT NOT NULL UNIQUE,
    continent      TEXT,                  -- 'EU', 'NA', ...
    cq_zone        INTEGER,               -- record default
    itu_zone       INTEGER,               -- record default
    latitude       REAL,
    longitude      REAL,
    utc_offset     REAL,
    deleted        INTEGER NOT NULL DEFAULT 0
);

CREATE INDEX idx_dxcc_entities_prefix ON dxcc_entities (primary_prefix);

-- Prefixes are matched longest-first:
--   SELECT ... WHERE ? GLOB prefix || '*' ORDER BY length(prefix) DESC LIMIT 1
-- cq_zone/itu_zone here OVERRIDE the entity default when non-NULL. About 75% of
-- rows carry one, so COALESCE them in every query:
--   COALESCE(p.cq_zone, e.cq_zone)
CREATE TABLE dxcc_prefixes (
    prefix      TEXT NOT NULL,
    entity_id   INTEGER NOT NULL REFERENCES dxcc_entities(id),
    exact       INTEGER NOT NULL DEFAULT 0,  -- 1 = whole callsign must match
    cq_zone     INTEGER,
    itu_zone    INTEGER,
    PRIMARY KEY (prefix, entity_id)
);

CREATE INDEX idx_dxcc_prefixes_len ON dxcc_prefixes (length(prefix) DESC);

-- ---------------------------------------------------------------------------
-- Operating reference
-- ---------------------------------------------------------------------------

CREATE TABLE qcodes (
    code        TEXT PRIMARY KEY,
    question    TEXT NOT NULL,
    answer      TEXT NOT NULL,
    category    TEXT            -- 'general', 'aeronautical', 'maritime'
);

CREATE TABLE prosigns (
    symbol      TEXT PRIMARY KEY,   -- 'AR', 'SK', 'BT'
    morse       TEXT NOT NULL,
    meaning     TEXT NOT NULL,
    usage       TEXT
);

CREATE TABLE phonetics (
    letter      TEXT PRIMARY KEY,
    word        TEXT NOT NULL,
    pronunciation TEXT
);

CREATE TABLE morse (
    character   TEXT PRIMARY KEY,
    code        TEXT NOT NULL,      -- '.-' with . and -
    category    TEXT NOT NULL       -- 'letter', 'digit', 'punctuation'
);

CREATE TABLE abbreviations (
    abbr        TEXT PRIMARY KEY,
    meaning     TEXT NOT NULL,
    context     TEXT                -- 'CW', 'general', 'contest'
);

-- RST readability/strength/tone scale
CREATE TABLE rst_scale (
    component   TEXT NOT NULL,      -- 'R', 'S', 'T'
    value       INTEGER NOT NULL,
    meaning     TEXT NOT NULL,
    PRIMARY KEY (component, value)
);

-- ---------------------------------------------------------------------------
-- Engineering reference
-- ---------------------------------------------------------------------------

-- Matched loss follows the usual two-term model:
--   loss_dB_per_100ft = k1 * sqrt(f_MHz) + k2 * f_MHz
CREATE TABLE coax_types (
    name        TEXT PRIMARY KEY,
    impedance_ohm REAL NOT NULL,
    velocity_factor REAL NOT NULL,
    capacitance_pf_per_ft REAL,
    outer_diameter_mm REAL,
    loss_k1     REAL,
    loss_k2     REAL,
    max_power_hf_w INTEGER,
    notes       TEXT
);

-- ---------------------------------------------------------------------------
-- NCDXF/IARU beacon network
-- ---------------------------------------------------------------------------

-- 18 stations, 10 s per slot, 3 min for a full cycle on each of 5 frequencies.
-- Which station is on which band at time t is pure arithmetic from slot_index.
CREATE TABLE ncdxf_beacons (
    slot_index  INTEGER PRIMARY KEY,    -- 0..17, order within the cycle
    callsign    TEXT NOT NULL,
    location    TEXT NOT NULL,
    grid        TEXT,
    latitude    REAL,
    longitude   REAL,
    dxcc_id     INTEGER REFERENCES dxcc_entities(id),
    active      INTEGER NOT NULL DEFAULT 1
);

CREATE TABLE ncdxf_frequencies (
    band_id     INTEGER PRIMARY KEY REFERENCES bands(id),
    freq_hz     INTEGER NOT NULL,
    slot_offset INTEGER NOT NULL        -- slots to add for this band
);
