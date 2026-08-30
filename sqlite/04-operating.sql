-- ---------------------------------------------------------------------------
-- Morse (ITU-R M.1677-1)
-- ---------------------------------------------------------------------------

INSERT INTO morse (character, code, category) VALUES
    ('A', '.-',    'letter'), ('B', '-...',  'letter'), ('C', '-.-.',  'letter'),
    ('D', '-..',   'letter'), ('E', '.',     'letter'), ('F', '..-.',  'letter'),
    ('G', '--.',   'letter'), ('H', '....',  'letter'), ('I', '..',    'letter'),
    ('J', '.---',  'letter'), ('K', '-.-',   'letter'), ('L', '.-..',  'letter'),
    ('M', '--',    'letter'), ('N', '-.',    'letter'), ('O', '---',   'letter'),
    ('P', '.--.',  'letter'), ('Q', '--.-',  'letter'), ('R', '.-.',   'letter'),
    ('S', '...',   'letter'), ('T', '-',     'letter'), ('U', '..-',   'letter'),
    ('V', '...-',  'letter'), ('W', '.--',   'letter'), ('X', '-..-',  'letter'),
    ('Y', '-.--',  'letter'), ('Z', '--..',  'letter'),
    ('0', '-----', 'digit'),  ('1', '.----', 'digit'),  ('2', '..---', 'digit'),
    ('3', '...--', 'digit'),  ('4', '....-', 'digit'),  ('5', '.....', 'digit'),
    ('6', '-....', 'digit'),  ('7', '--...', 'digit'),  ('8', '---..', 'digit'),
    ('9', '----.', 'digit'),
    ('.',  '.-.-.-', 'punctuation'), (',',  '--..--', 'punctuation'),
    ('?',  '..--..', 'punctuation'), ('''', '.----.', 'punctuation'),
    ('!',  '-.-.--', 'punctuation'), ('/',  '-..-.',  'punctuation'),
    ('(',  '-.--.',  'punctuation'), (')',  '-.--.-', 'punctuation'),
    ('&',  '.-...',  'punctuation'), (':',  '---...', 'punctuation'),
    (';',  '-.-.-.', 'punctuation'), ('=',  '-...-',  'punctuation'),
    ('+',  '.-.-.',  'punctuation'), ('-',  '-....-', 'punctuation'),
    ('_',  '..--.-', 'punctuation'), ('"',  '.-..-.', 'punctuation'),
    ('$',  '...-..-','punctuation'), ('@',  '.--.-.', 'punctuation');

-- ---------------------------------------------------------------------------
-- ITU/NATO phonetics
-- ---------------------------------------------------------------------------

INSERT INTO phonetics (letter, word, pronunciation) VALUES
    ('A', 'Alfa',     'AL-FAH'),      ('B', 'Bravo',    'BRAH-VOH'),
    ('C', 'Charlie',  'CHAR-LEE'),    ('D', 'Delta',    'DELL-TAH'),
    ('E', 'Echo',     'ECK-OH'),      ('F', 'Foxtrot',  'FOKS-TROT'),
    ('G', 'Golf',     'GOLF'),        ('H', 'Hotel',    'HOH-TELL'),
    ('I', 'India',    'IN-DEE-AH'),   ('J', 'Juliett',  'JEW-LEE-ETT'),
    ('K', 'Kilo',     'KEY-LOH'),     ('L', 'Lima',     'LEE-MAH'),
    ('M', 'Mike',     'MIKE'),        ('N', 'November', 'NO-VEM-BER'),
    ('O', 'Oscar',    'OSS-CAH'),     ('P', 'Papa',     'PAH-PAH'),
    ('Q', 'Quebec',   'KEH-BECK'),    ('R', 'Romeo',    'ROW-ME-OH'),
    ('S', 'Sierra',   'SEE-AIR-RAH'), ('T', 'Tango',    'TANG-GO'),
    ('U', 'Uniform',  'YOU-NEE-FORM'),('V', 'Victor',   'VIK-TAH'),
    ('W', 'Whiskey',  'WISS-KEY'),    ('X', 'X-ray',    'ECKS-RAY'),
    ('Y', 'Yankee',   'YANG-KEY'),    ('Z', 'Zulu',     'ZOO-LOO'),
    ('0', 'Zero',     'ZEE-RO'),      ('1', 'One',      'WUN'),
    ('2', 'Two',      'TOO'),         ('3', 'Three',    'TREE'),
    ('4', 'Four',     'FOW-ER'),      ('5', 'Five',     'FIFE'),
    ('6', 'Six',      'SIX'),         ('7', 'Seven',    'SEV-EN'),
    ('8', 'Eight',    'AIT'),         ('9', 'Nine',     'NIN-ER');

-- ---------------------------------------------------------------------------
-- Q-codes (amateur-relevant subset)
-- ---------------------------------------------------------------------------

INSERT INTO qcodes (code, question, answer, category) VALUES
    ('QRA', 'What is the name of your station?', 'The name of my station is ...', 'general'),
    ('QRG', 'Will you tell me my exact frequency?', 'Your exact frequency is ... kHz', 'general'),
    ('QRK', 'What is the readability of my signals?', 'The readability of your signals is ... (1 to 5)', 'general'),
    ('QRL', 'Are you busy?', 'I am busy, please do not interfere', 'general'),
    ('QRM', 'Is my transmission being interfered with?', 'Your transmission is being interfered with', 'general'),
    ('QRN', 'Are you troubled by static?', 'I am troubled by static', 'general'),
    ('QRO', 'Shall I increase transmit power?', 'Increase transmit power', 'general'),
    ('QRP', 'Shall I decrease transmit power?', 'Decrease transmit power', 'general'),
    ('QRQ', 'Shall I send faster?', 'Send faster (... words per minute)', 'general'),
    ('QRS', 'Shall I send more slowly?', 'Send more slowly (... words per minute)', 'general'),
    ('QRT', 'Shall I stop sending?', 'Stop sending', 'general'),
    ('QRU', 'Have you anything for me?', 'I have nothing for you', 'general'),
    ('QRV', 'Are you ready?', 'I am ready', 'general'),
    ('QRX', 'When will you call me again?', 'I will call you again at ...', 'general'),
    ('QRZ', 'Who is calling me?', 'You are being called by ...', 'general'),
    ('QSA', 'What is the strength of my signals?', 'The strength of your signals is ... (1 to 5)', 'general'),
    ('QSB', 'Are my signals fading?', 'Your signals are fading', 'general'),
    ('QSK', 'Can you hear me between your signals?', 'I can hear you between my signals', 'general'),
    ('QSL', 'Can you acknowledge receipt?', 'I acknowledge receipt', 'general'),
    ('QSO', 'Can you communicate with ... directly?', 'I can communicate with ... directly', 'general'),
    ('QSP', 'Will you relay to ...?', 'I will relay to ...', 'general'),
    ('QSY', 'Shall I change frequency?', 'Change frequency to ...', 'general'),
    ('QTC', 'How many messages have you to send?', 'I have ... messages for you', 'general'),
    ('QTH', 'What is your position?', 'My position is ...', 'general'),
    ('QTR', 'What is the correct time?', 'The correct time is ...', 'general');

-- ---------------------------------------------------------------------------
-- Prosigns
-- ---------------------------------------------------------------------------

INSERT INTO prosigns (symbol, morse, meaning, usage) VALUES
    ('AR', '.-.-.',    'End of message',        'Sent at the end of a transmission to a specific station'),
    ('AS', '.-...',    'Wait / stand by',       'Asking the other station to hold'),
    ('BK', '-...-.-',  'Break',                 'Interrupting to hand over quickly'),
    ('BT', '-...-',    'Separator',             'Between paragraphs or sections; sent as a long dash'),
    ('CL', '-.-..-..', 'Closing station',       'Going off the air entirely'),
    ('CT', '-.-.-',    'Attention / start',     'Marks the beginning of a transmission'),
    ('HH', '........', 'Error',                 'Eight dits, meaning the last word was wrong'),
    ('KN', '-.--.',    'Go ahead, named station only', 'Invites only the station being worked to reply'),
    ('SK', '...-.-',   'End of contact',        'Final transmission of a QSO'),
    ('SN', '...-.',    'Understood',            'Also written VE'),
    ('SOS', '...---...', 'Distress',            'International distress signal; sent as one symbol');

-- ---------------------------------------------------------------------------
-- CW abbreviations
-- ---------------------------------------------------------------------------

INSERT INTO abbreviations (abbr, meaning, context) VALUES
    ('73',   'Best regards',                'general'),
    ('88',   'Love and kisses',             'general'),
    ('ABT',  'About',                       'CW'),
    ('AGN',  'Again',                       'CW'),
    ('ANT',  'Antenna',                     'CW'),
    ('BURO', 'QSL bureau',                  'general'),
    ('CFM',  'Confirm',                     'CW'),
    ('CQ',   'Calling any station',         'general'),
    ('CUL',  'See you later',               'CW'),
    ('DE',   'From (this is)',              'CW'),
    ('DX',   'Distance / long-distance station', 'general'),
    ('ES',   'And',                         'CW'),
    ('FB',   'Fine business (excellent)',   'CW'),
    ('GA',   'Good afternoon / go ahead',   'CW'),
    ('GE',   'Good evening',                'CW'),
    ('GM',   'Good morning',                'CW'),
    ('HI',   'Laughter',                    'CW'),
    ('HW',   'How copy?',                   'CW'),
    ('K',    'Invitation to transmit',      'CW'),
    ('OM',   'Old man (any operator)',      'CW'),
    ('PSE',  'Please',                      'CW'),
    ('PWR',  'Power',                       'CW'),
    ('RIG',  'Station equipment',           'general'),
    ('RPT',  'Repeat',                      'CW'),
    ('RST',  'Readability, strength, tone', 'general'),
    ('RX',   'Receiver',                    'general'),
    ('SIG',  'Signal',                      'CW'),
    ('SK',   'Silent key (deceased operator)', 'general'),
    ('SRI',  'Sorry',                       'CW'),
    ('TNX',  'Thanks',                      'CW'),
    ('TU',   'Thank you',                   'CW'),
    ('TX',   'Transmitter',                 'general'),
    ('UR',   'Your / you are',              'CW'),
    ('VY',   'Very',                        'CW'),
    ('WX',   'Weather',                     'CW'),
    ('XYL',  'Wife',                        'CW'),
    ('YL',   'Young lady (female operator)','CW');

-- ---------------------------------------------------------------------------
-- RST scale
-- ---------------------------------------------------------------------------

INSERT INTO rst_scale (component, value, meaning) VALUES
    ('R', 1, 'Unreadable'),
    ('R', 2, 'Barely readable, occasional words distinguishable'),
    ('R', 3, 'Readable with considerable difficulty'),
    ('R', 4, 'Readable with practically no difficulty'),
    ('R', 5, 'Perfectly readable'),
    ('S', 1, 'Faint, signals barely perceptible'),
    ('S', 2, 'Very weak'),
    ('S', 3, 'Weak'),
    ('S', 4, 'Fair'),
    ('S', 5, 'Fairly good'),
    ('S', 6, 'Good'),
    ('S', 7, 'Moderately strong'),
    ('S', 8, 'Strong'),
    ('S', 9, 'Extremely strong'),
    ('T', 1, 'Extremely rough hissing note'),
    ('T', 2, 'Very rough AC note, no trace of musicality'),
    ('T', 3, 'Rough, low-pitched AC note, slightly musical'),
    ('T', 4, 'Rather rough AC note, moderately musical'),
    ('T', 5, 'Musically modulated note'),
    ('T', 6, 'Modulated note, slight trace of whistle'),
    ('T', 7, 'Near DC note, smooth ripple'),
    ('T', 8, 'Good DC note, trace of ripple'),
    ('T', 9, 'Purest DC note');
