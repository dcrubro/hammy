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
-- ---------------------------------------------------------------------------

-- 2200m and 630m: all classes, strict EIRP limits, notification required
INSERT INTO band_segments (band_id, country, class_id, low_hz, high_hz, modes, max_power_w, notes) VALUES
    (1, 'US', 1, 135700, 137800, 'CW,DATA', NULL, '1 W EIRP maximum'),
    (1, 'US', 3, 135700, 137800, 'CW,DATA', NULL, '1 W EIRP maximum'),
    (1, 'US', 4, 135700, 137800, 'CW,DATA', NULL, '1 W EIRP maximum'),
    (2, 'US', 1, 472000, 479000, 'CW,DATA', NULL, '5 W EIRP maximum'),
    (2, 'US', 3, 472000, 479000, 'CW,DATA', NULL, '5 W EIRP maximum'),
    (2, 'US', 4, 472000, 479000, 'CW,DATA', NULL, '5 W EIRP maximum');

-- 160m: General and above, full band
INSERT INTO band_segments (band_id, country, class_id, low_hz, high_hz, modes, max_power_w, notes) VALUES
    (3, 'US', 1, 1800000, 2000000, 'CW,DATA,PHONE,IMAGE', NULL, NULL),
    (3, 'US', 2, 1800000, 2000000, 'CW,DATA,PHONE,IMAGE', NULL, NULL),
    (3, 'US', 3, 1800000, 2000000, 'CW,DATA,PHONE,IMAGE', NULL, NULL);

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

-- 60m: five discrete channels, General and above.
-- Stored as channel-width ranges; centre frequency is the USB dial + 1.5 kHz.
INSERT INTO band_segments (band_id, country, class_id, low_hz, high_hz, modes, max_power_w, notes) VALUES
    (5, 'US', 1, 5330500, 5333300, 'CW,DATA,PHONE', NULL, 'Channel 1, 100 W ERP, USB'),
    (5, 'US', 1, 5346500, 5349300, 'CW,DATA,PHONE', NULL, 'Channel 2, 100 W ERP, USB'),
    (5, 'US', 1, 5357000, 5359800, 'CW,DATA,PHONE', NULL, 'Channel 3, 100 W ERP, USB'),
    (5, 'US', 1, 5371500, 5374300, 'CW,DATA,PHONE', NULL, 'Channel 4, 100 W ERP, USB'),
    (5, 'US', 1, 5403500, 5406300, 'CW,DATA,PHONE', NULL, 'Channel 5, 100 W ERP, USB'),
    (5, 'US', 3, 5330500, 5333300, 'CW,DATA,PHONE', NULL, 'Channel 1, 100 W ERP, USB'),
    (5, 'US', 3, 5346500, 5349300, 'CW,DATA,PHONE', NULL, 'Channel 2, 100 W ERP, USB'),
    (5, 'US', 3, 5357000, 5359800, 'CW,DATA,PHONE', NULL, 'Channel 3, 100 W ERP, USB'),
    (5, 'US', 3, 5371500, 5374300, 'CW,DATA,PHONE', NULL, 'Channel 4, 100 W ERP, USB'),
    (5, 'US', 3, 5403500, 5406300, 'CW,DATA,PHONE', NULL, 'Channel 5, 100 W ERP, USB');

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

-- 30m: no phone or image anywhere, 200 W limit
INSERT INTO band_segments (band_id, country, class_id, low_hz, high_hz, modes, max_power_w, notes) VALUES
    (7, 'US', 1, 10100000, 10150000, 'CW,DATA', 200, 'No phone or image permitted'),
    (7, 'US', 2, 10100000, 10150000, 'CW,DATA', 200, 'No phone or image permitted'),
    (7, 'US', 3, 10100000, 10150000, 'CW,DATA', 200, 'No phone or image permitted');

-- 20m
INSERT INTO band_segments (band_id, country, class_id, low_hz, high_hz, modes, max_power_w, notes) VALUES
    (8, 'US', 1, 14000000, 14150000, 'CW,DATA',     NULL, NULL),
    (8, 'US', 1, 14150000, 14350000, 'PHONE,IMAGE', NULL, NULL),
    (8, 'US', 2, 14025000, 14150000, 'CW,DATA',     NULL, NULL),
    (8, 'US', 2, 14175000, 14350000, 'PHONE,IMAGE', NULL, NULL),
    (8, 'US', 3, 14025000, 14150000, 'CW,DATA',     NULL, NULL),
    (8, 'US', 3, 14225000, 14350000, 'PHONE,IMAGE', NULL, NULL);

-- 17m
INSERT INTO band_segments (band_id, country, class_id, low_hz, high_hz, modes, max_power_w, notes) VALUES
    (9, 'US', 1, 18068000, 18110000, 'CW,DATA',     NULL, NULL),
    (9, 'US', 1, 18110000, 18168000, 'PHONE,IMAGE', NULL, NULL),
    (9, 'US', 2, 18068000, 18110000, 'CW,DATA',     NULL, NULL),
    (9, 'US', 2, 18110000, 18168000, 'PHONE,IMAGE', NULL, NULL),
    (9, 'US', 3, 18068000, 18110000, 'CW,DATA',     NULL, NULL),
    (9, 'US', 3, 18110000, 18168000, 'PHONE,IMAGE', NULL, NULL);

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

-- 12m
INSERT INTO band_segments (band_id, country, class_id, low_hz, high_hz, modes, max_power_w, notes) VALUES
    (11, 'US', 1, 24890000, 24930000, 'CW,DATA',     NULL, NULL),
    (11, 'US', 1, 24930000, 24990000, 'PHONE,IMAGE', NULL, NULL),
    (11, 'US', 2, 24890000, 24930000, 'CW,DATA',     NULL, NULL),
    (11, 'US', 2, 24930000, 24990000, 'PHONE,IMAGE', NULL, NULL),
    (11, 'US', 3, 24890000, 24930000, 'CW,DATA',     NULL, NULL),
    (11, 'US', 3, 24930000, 24990000, 'PHONE,IMAGE', NULL, NULL);

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

-- VHF/UHF and above: Technician and higher, full allocations
INSERT INTO band_segments (band_id, country, class_id, low_hz, high_hz, modes, max_power_w, notes) VALUES
    (13, 'US', 4, 50000000,   50100000,   'CW',                    NULL, 'CW only below 50.1 MHz'),
    (13, 'US', 4, 50100000,   54000000,   'CW,DATA,PHONE,IMAGE',   NULL, NULL),
    (14, 'US', 4, 144000000,  144100000,  'CW',                    NULL, 'CW only below 144.1 MHz'),
    (14, 'US', 4, 144100000,  148000000,  'CW,DATA,PHONE,IMAGE',   NULL, NULL),
    (15, 'US', 4, 222000000,  225000000,  'CW,DATA,PHONE,IMAGE',   NULL, NULL),
    (16, 'US', 4, 420000000,  450000000,  'CW,DATA,PHONE,IMAGE',   NULL, 'Geographic restrictions apply near some radar sites'),
    (17, 'US', 4, 902000000,  928000000,  'CW,DATA,PHONE,IMAGE',   NULL, 'Secondary allocation, shared with Part 15 devices'),
    (18, 'US', 4, 1240000000, 1300000000, 'CW,DATA,PHONE,IMAGE',   NULL, NULL);

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
