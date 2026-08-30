-- ---------------------------------------------------------------------------
-- Coax
--
-- Impedance, velocity factor and capacitance are nominal published figures.
-- loss_k1/loss_k2 are intentionally NULL: matched loss varies enough between
-- manufacturers of nominally the same cable that a generic approximation would
-- give the calculator false precision. Populate from the datasheet of the cable
-- you actually mean.
-- ---------------------------------------------------------------------------

INSERT INTO coax_types (name, impedance_ohm, velocity_factor, capacitance_pf_per_ft, outer_diameter_mm, loss_k1, loss_k2, notes) VALUES
    ('RG-58C/U',     50.0, 0.66, 30.8, 4.95,  NULL, NULL, 'Thin, lossy, common for short VHF jumpers'),
    ('RG-8X',        50.0, 0.82, 25.0, 6.10,  NULL, NULL, 'Foam dielectric, a middle ground'),
    ('RG-213/U',     50.0, 0.66, 30.8, 10.30, NULL, NULL, 'Workhorse HF cable'),
    ('RG-214/U',     50.0, 0.66, 30.8, 10.80, NULL, NULL, 'Double-shielded RG-213 equivalent'),
    ('LMR-400',      50.0, 0.85, 23.9, 10.29, NULL, NULL, 'Low loss, common for VHF/UHF runs'),
    ('LMR-600',      50.0, 0.87, 23.4, 14.99, NULL, NULL, 'Lower loss, stiffer'),
    ('RG-6/U',       75.0, 0.83, 16.2, 6.90,  NULL, NULL, '75 ohm, cheap, fine for receive'),
    ('RG-11/U',      75.0, 0.66, 20.6, 10.30, NULL, NULL, '75 ohm, lower loss than RG-6'),
    ('RG-174/U',     50.0, 0.66, 30.8, 2.55,  NULL, NULL, 'Very thin, very lossy, patch use only'),
    ('Belden 9913',  50.0, 0.84, 24.6, 10.30, NULL, NULL, 'Air dielectric, needs care against water ingress'),
    ('Hardline LDF4-50A', 50.0, 0.88, 25.9, 15.90, NULL, NULL, '1/2 inch corrugated hardline');

-- ---------------------------------------------------------------------------
-- NCDXF/IARU beacons
--
-- 18 stations, one 10 s slot each, 180 s for a full cycle per band.
-- Station transmitting on a given band at UTC time t:
--   slot = (floor(t / 10) - slot_offset) mod 18
-- ---------------------------------------------------------------------------

INSERT INTO ncdxf_beacons (slot_index, callsign, location, grid, latitude, longitude, dxcc_id) VALUES
    (0,  '4U1UN',  'United Nations, New York', 'FN30AS',  40.75,   -73.97, NULL),
    (1,  'VE8AT',  'Inuvik, NT, Canada',       'CP38GJ',  68.38,  -133.72, 1),
    (2,  'W6WX',   'Mt Umunhum, CA, USA',      'CM97BD',  37.16,  -121.90, 291),
    (3,  'KH6RS',  'Maui, Hawaii',             'BL10TS',  20.79,  -156.46, NULL),
    (4,  'ZL6B',   'Masterton, New Zealand',   'RE78TW', -40.92,   175.61, 170),
    (5,  'VK6RBP', 'Rolystone, WA, Australia', 'OF87AV', -32.11,   116.05, 150),
    (6,  'JA2IGY', 'Mt Asama, Japan',          'PM84JK',  34.45,   136.79, 339),
    (7,  'RR9O',   'Novosibirsk, Russia',      'NO14KX',  54.98,    82.89, NULL),
    (8,  'VR2B',   'Hong Kong',                'OL72BG',  22.28,   114.16, NULL),
    (9,  '4S7B',   'Colombo, Sri Lanka',       'MJ96WV',   6.91,    79.87, NULL),
    (10, 'ZS6DN',  'Pretoria, South Africa',   'KG33XI', -25.90,    28.26, 462),
    (11, '5Z4B',   'Kariobangi, Kenya',        'KI88HR',  -1.24,    36.89, NULL),
    (12, '4X6TU',  'Tel Aviv, Israel',         'KM72JB',  32.05,    34.78, NULL),
    (13, 'OH2B',   'Lohja, Finland',           'KP20EH',  60.25,    24.40, 224),
    (14, 'CS3B',   'Madeira',                  'IM12JT',  32.72,   -16.99, NULL),
    (15, 'LU4AA',  'Buenos Aires, Argentina',  'GF05TJ', -34.62,   -58.37, 100),
    (16, 'OA4B',   'Lima, Peru',               'FH17MW', -12.07,   -77.03, NULL),
    (17, 'YV5B',   'Caracas, Venezuela',       'FJ69CC',  10.50,   -66.92, NULL);

INSERT INTO ncdxf_frequencies (band_id, freq_hz, slot_offset) VALUES
    (8,  14100000, 0),
    (9,  18110000, 1),
    (10, 21150000, 2),
    (11, 24930000, 3),
    (12, 28200000, 4);
