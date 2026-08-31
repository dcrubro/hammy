-- ---------------------------------------------------------------------------
-- Bands
-- ---------------------------------------------------------------------------

INSERT INTO bands (id, name, edge_low_hz, edge_high_hz, wavelength_m, sort_order) VALUES
    (1,  '2200m',  135700,      137800,     2200, 10),
    (2,  '630m',   472000,      479000,     630,  20),
    (3,  '160m',   1800000,     2000000,    160,  30),
    (4,  '80m',    3500000,     4000000,    80,   40),
    (5,  '60m',    5330500,     5406400,    60,   50),
    (6,  '40m',    7000000,     7300000,    40,   60),
    (7,  '30m',    10100000,    10150000,   30,   70),
    (8,  '20m',    14000000,    14350000,   20,   80),
    (9,  '17m',    18068000,    18168000,   17,   90),
    (10, '15m',    21000000,    21450000,   15,   100),
    (11, '12m',    24890000,    24990000,   12,   110),
    (12, '10m',    28000000,    29700000,   10,   120),
    (13, '6m',     50000000,    54000000,   6,    130),
    (14, '2m',     144000000,   148000000,  2,    140),
    (15, '1.25m',  222000000,   225000000,  1.25, 150),
    (16, '70cm',   420000000,   450000000,  0.70, 160),
    (17, '33cm',   902000000,   928000000,  0.33, 170),
    (18, '23cm',   1240000000,  1300000000, 0.23, 180);

-- ---------------------------------------------------------------------------
-- US license classes
-- ---------------------------------------------------------------------------

INSERT INTO license_classes (id, country, code, name, rank, notes) VALUES
    (1, 'US', 'E', 'Amateur Extra', 50, NULL),
    (2, 'US', 'A', 'Advanced',      40, 'Closed to new issue since 1 April 2000; existing licences remain valid.'),
    (3, 'US', 'G', 'General',       30, NULL),
    (4, 'US', 'T', 'Technician',    20, NULL),
    (5, 'US', 'N', 'Novice',        10, 'Closed to new issue since 1 April 2000; existing licences remain valid.');

-- ---------------------------------------------------------------------------
-- US band segments (47 CFR Part 97)
--
-- VERIFY BEFORE SHIPPING. Hand-entered from the Part 97 privilege tables.
-- Wrong edges or wrong privileges can put an operator outside their licence.
--
-- Two shapes are used here, deliberately:
--
--   1. Bands where every eligible class gets the SAME range are generated with
--      INSERT..SELECT over license_classes and a rank threshold. The rule is
--      stated once, in the WHERE clause, and the rows follow from it.
--
--   2. Bands where classes get GENUINELY DIFFERENT ranges (most of HF: Extra
--      has 14.000-14.150 where General has 14.025-14.150) are written out
--      explicitly, one row per class. A rank threshold cannot express that.
--
-- Shape 1 exists because hand-enumerating six bands times five classes is
-- thirty near-identical rows, and the first version of this file missed several
-- of them - Advanced was absent from 2200m, 630m and 60m entirely, and VHF/UHF
-- was seeded for Technician only, so an Extra was told they had no 2m access.
-- audit.py's privilege-nesting check catches that class of mistake now, but not
-- making it is better.
-- ---------------------------------------------------------------------------

-- 2200m and 630m: all classes. Strict EIRP limits, and the operator must notify
-- UTC and await a response before transmitting.
-- VERIFY: whether Novice holds these is the part I am least sure of.
INSERT INTO band_segments (band_id, country, class_id, low_hz, high_hz, modes, max_power_w, notes)
SELECT v.band_id, 'US', lc.id, v.low_hz, v.high_hz, v.modes, v.max_power_w, v.notes
  FROM license_classes lc
  JOIN (
        SELECT 1 AS band_id, 135700 AS low_hz, 137800 AS high_hz,
               'CW,DATA' AS modes, NULL AS max_power_w, '1 W EIRP maximum' AS notes
  UNION SELECT 2, 472000, 479000, 'CW,DATA', NULL, '5 W EIRP maximum'
  ) v
 WHERE lc.country = 'US';

-- 160m, 30m, 17m, 12m: General and above (rank >= 30), whole band, same for all.
INSERT INTO band_segments (band_id, country, class_id, low_hz, high_hz, modes, max_power_w, notes)
SELECT v.band_id, 'US', lc.id, v.low_hz, v.high_hz, v.modes, v.max_power_w, v.notes
  FROM license_classes lc
  JOIN (
        SELECT 3 AS band_id, 1800000 AS low_hz, 2000000 AS high_hz,
               'CW,DATA,PHONE,IMAGE' AS modes, NULL AS max_power_w, NULL AS notes
  UNION SELECT 7,  10100000, 10150000, 'CW,DATA',     200,  'No phone or image permitted'
  UNION SELECT 9,  18068000, 18110000, 'CW,DATA',     NULL, NULL
  UNION SELECT 9,  18110000, 18168000, 'PHONE,IMAGE', NULL, NULL
  UNION SELECT 11, 24890000, 24930000, 'CW,DATA',     NULL, NULL
  UNION SELECT 11, 24930000, 24990000, 'PHONE,IMAGE', NULL, NULL
  ) v
 WHERE lc.country = 'US' AND lc.rank >= 30;

-- 60m: five discrete channels, General and above. Stored as channel-width
-- ranges; the USB dial frequency is the channel centre minus 1.5 kHz.
INSERT INTO band_segments (band_id, country, class_id, low_hz, high_hz, modes, max_power_w, notes)
SELECT 5, 'US', lc.id, v.low_hz, v.high_hz, 'CW,DATA,PHONE', NULL, v.notes
  FROM license_classes lc
  JOIN (
        SELECT 5330500 AS low_hz, 5333300 AS high_hz, 'Channel 1, 100 W ERP, USB' AS notes
  UNION SELECT 5346500, 5349300, 'Channel 2, 100 W ERP, USB'
  UNION SELECT 5357000, 5359800, 'Channel 3, 100 W ERP, USB'
  UNION SELECT 5371500, 5374300, 'Channel 4, 100 W ERP, USB'
  UNION SELECT 5403500, 5406300, 'Channel 5, 100 W ERP, USB'
  ) v
 WHERE lc.country = 'US' AND lc.rank >= 30;

-- VHF/UHF and above: Technician and higher (rank >= 20) hold the full
-- allocation. There is no per-class variation above 50 MHz except for Novice.
INSERT INTO band_segments (band_id, country, class_id, low_hz, high_hz, modes, max_power_w, notes)
SELECT v.band_id, 'US', lc.id, v.low_hz, v.high_hz, v.modes, v.max_power_w, v.notes
  FROM license_classes lc
  JOIN (
        SELECT 13 AS band_id, 50000000 AS low_hz, 50100000 AS high_hz,
               'CW' AS modes, NULL AS max_power_w, 'CW only below 50.1 MHz' AS notes
  UNION SELECT 13, 50100000,   54000000,   'CW,DATA,PHONE,IMAGE', NULL, NULL
  UNION SELECT 14, 144000000,  144100000,  'CW',                  NULL, 'CW only below 144.1 MHz'
  UNION SELECT 14, 144100000,  148000000,  'CW,DATA,PHONE,IMAGE', NULL, NULL
  UNION SELECT 15, 222000000,  225000000,  'CW,DATA,PHONE,IMAGE', NULL, NULL
  UNION SELECT 16, 420000000,  450000000,  'CW,DATA,PHONE,IMAGE', NULL,
               'Geographic restrictions apply near some radar sites'
  UNION SELECT 17, 902000000,  928000000,  'CW,DATA,PHONE,IMAGE', NULL,
               'Secondary allocation, shared with Part 15 devices'
  UNION SELECT 18, 1240000000, 1300000000, 'CW,DATA,PHONE,IMAGE', NULL, NULL
  ) v
 WHERE lc.country = 'US' AND lc.rank >= 20;

-- Novice above 50 MHz: two reduced-power slices and nothing else.
-- VERIFY: Novice licences have not been issued since 2000, so an error here
-- would go unnoticed for years.
INSERT INTO band_segments (band_id, country, class_id, low_hz, high_hz, modes, max_power_w, notes)
SELECT v.band_id, 'US', lc.id, v.low_hz, v.high_hz, 'CW,DATA,PHONE,IMAGE', v.max_power_w,
       'Novice segment, reduced power'
  FROM license_classes lc
  JOIN (
        SELECT 15 AS band_id, 222000000 AS low_hz, 225000000 AS high_hz, 25 AS max_power_w
  UNION SELECT 18, 1270000000, 1295000000, 5
  ) v
 WHERE lc.country = 'US' AND lc.code = 'N';

-- ---------------------------------------------------------------------------
-- Bands where classes get genuinely different ranges. Written out explicitly:
-- a rank threshold cannot express "Extra from 3.500, General from 3.525".
-- ---------------------------------------------------------------------------

-- 80m / 75m
INSERT INTO band_segments (band_id, country, class_id, low_hz, high_hz, modes, max_power_w, notes) VALUES
    (4, 'US', 1, 3500000, 3600000, 'CW,DATA',     NULL, NULL),
    (4, 'US', 1, 3600000, 4000000, 'PHONE,IMAGE', NULL, NULL),
    (4, 'US', 2, 3525000, 3600000, 'CW,DATA',     NULL, NULL),
    (4, 'US', 2, 3700000, 4000000, 'PHONE,IMAGE', NULL, NULL),
    (4, 'US', 3, 3525000, 3600000, 'CW,DATA',     NULL, NULL),
    (4, 'US', 3, 3800000, 4000000, 'PHONE,IMAGE', NULL, NULL),
    (4, 'US', 4, 3525000, 3600000, 'CW',          200,  'CW only'),
    (4, 'US', 5, 3525000, 3600000, 'CW',          200,  'CW only');

-- 40m
INSERT INTO band_segments (band_id, country, class_id, low_hz, high_hz, modes, max_power_w, notes) VALUES
    (6, 'US', 1, 7000000, 7125000, 'CW,DATA',     NULL, NULL),
    (6, 'US', 1, 7125000, 7300000, 'PHONE,IMAGE', NULL, NULL),
    (6, 'US', 2, 7025000, 7125000, 'CW,DATA',     NULL, NULL),
    (6, 'US', 2, 7125000, 7300000, 'PHONE,IMAGE', NULL, NULL),
    (6, 'US', 3, 7025000, 7125000, 'CW,DATA',     NULL, NULL),
    (6, 'US', 3, 7175000, 7300000, 'PHONE,IMAGE', NULL, NULL),
    (6, 'US', 4, 7025000, 7125000, 'CW',          200,  'CW only'),
    (6, 'US', 5, 7025000, 7125000, 'CW',          200,  'CW only');

-- 20m
INSERT INTO band_segments (band_id, country, class_id, low_hz, high_hz, modes, max_power_w, notes) VALUES
    (8, 'US', 1, 14000000, 14150000, 'CW,DATA',     NULL, NULL),
    (8, 'US', 1, 14150000, 14350000, 'PHONE,IMAGE', NULL, NULL),
    (8, 'US', 2, 14025000, 14150000, 'CW,DATA',     NULL, NULL),
    (8, 'US', 2, 14175000, 14350000, 'PHONE,IMAGE', NULL, NULL),
    (8, 'US', 3, 14025000, 14150000, 'CW,DATA',     NULL, NULL),
    (8, 'US', 3, 14225000, 14350000, 'PHONE,IMAGE', NULL, NULL);

-- 15m
INSERT INTO band_segments (band_id, country, class_id, low_hz, high_hz, modes, max_power_w, notes) VALUES
    (10, 'US', 1, 21000000, 21200000, 'CW,DATA',     NULL, NULL),
    (10, 'US', 1, 21200000, 21450000, 'PHONE,IMAGE', NULL, NULL),
    (10, 'US', 2, 21025000, 21200000, 'CW,DATA',     NULL, NULL),
    (10, 'US', 2, 21225000, 21450000, 'PHONE,IMAGE', NULL, NULL),
    (10, 'US', 3, 21025000, 21200000, 'CW,DATA',     NULL, NULL),
    (10, 'US', 3, 21275000, 21450000, 'PHONE,IMAGE', NULL, NULL),
    (10, 'US', 4, 21025000, 21200000, 'CW',          200,  'CW only'),
    (10, 'US', 5, 21025000, 21200000, 'CW',          200,  'CW only');

-- 10m: the only HF band with Technician phone privileges
INSERT INTO band_segments (band_id, country, class_id, low_hz, high_hz, modes, max_power_w, notes) VALUES
    (12, 'US', 1, 28000000, 28300000, 'CW,DATA',     NULL, NULL),
    (12, 'US', 1, 28300000, 29700000, 'PHONE,IMAGE', NULL, NULL),
    (12, 'US', 2, 28000000, 28300000, 'CW,DATA',     NULL, NULL),
    (12, 'US', 2, 28300000, 29700000, 'PHONE,IMAGE', NULL, NULL),
    (12, 'US', 3, 28000000, 28300000, 'CW,DATA',     NULL, NULL),
    (12, 'US', 3, 28300000, 29700000, 'PHONE,IMAGE', NULL, NULL),
    (12, 'US', 4, 28000000, 28300000, 'CW,DATA',     200,  NULL),
    (12, 'US', 4, 28300000, 28500000, 'PHONE',       200,  'Technician phone privileges'),
    (12, 'US', 5, 28100000, 28300000, 'CW,DATA',     200,  NULL),
    (12, 'US', 5, 28300000, 28500000, 'PHONE',       200,  NULL);

-- ---------------------------------------------------------------------------
-- IARU allocation extents (class_id NULL = the allocation, not privileges)
-- Partial. Enough to answer "is 7.250 legal here" for Region 1 vs 2.
-- ---------------------------------------------------------------------------

INSERT INTO band_segments (band_id, country, iaru_region, class_id, low_hz, high_hz, modes, notes) VALUES
    (3,  '', 1, NULL, 1810000,   2000000,   'ALL', 'Varies by country within R1'),
    (4,  '', 1, NULL, 3500000,   3800000,   'ALL', NULL),
    (6,  '', 1, NULL, 7000000,   7200000,   'ALL', NULL),
    (8,  '', 1, NULL, 14000000,  14350000,  'ALL', NULL),
    (10, '', 1, NULL, 21000000,  21450000,  'ALL', NULL),
    (12, '', 1, NULL, 28000000,  29700000,  'ALL', NULL),
    (14, '', 1, NULL, 144000000, 146000000, 'ALL', NULL),
    (16, '', 1, NULL, 430000000, 440000000, 'ALL', 'Varies by country within R1'),
    (4,  '', 3, NULL, 3500000,   3900000,   'ALL', 'Varies by country within R3'),
    (6,  '', 3, NULL, 7000000,   7200000,   'ALL', NULL),
    (14, '', 3, NULL, 144000000, 148000000, 'ALL', NULL);
