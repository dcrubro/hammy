# Hammy
A Discord Bot for Ham/Amateur Radio

Fun fact: The logo of Hammy is a function! It is: f(x) = e^(-x^2)sin(9x)

## Features
Current features:
- /freq &lt;frequency (MHz)&gt; [country (default: US)] - Show the band, segment and who can transmit (for that country).
- /abbr &lt;abbreviation&gt; - Convert Abbreviation to Meaning and Context of Meaning.
- /q &lt;q-code&gt; - Convert Q-Code to Question/Answer.
- /phonetic &lt;text&gt; - Convert Text to Phonetics (useful for callsigns); If text is under 12 characters, also shows pronunciaction.
- /morse &lt;text&gt; - Convert Text to Morse Code.
- /ping - Ping the Bot.

Currently in-development, many features planned!

## Architecture
Hammy is written in C, using the [Concord Library](https://github.com/Cogmasters/concord). It's multithreaded, with a thread pool system for queuing jobs.

User interactions can be of two types:
- Instant Interactions: Handled directly by the master thread, don't require any communication with the backend, performed on-bot.
- Non-Instant Interactions: Queued into the job pool, where a worker thread picks them up (handoff) for processing in the background and responds later.

## AI Disclosure
AI tools were used responsibly in the creation of this project, mainly for cmakelists off a pre-made template. It has also been used for minor things like functions, reviews, commits, etc.
Contributors are responsible for their commits, regardless of the usage of AI or not.

## Legal
Licensed under the GPLv3 license, with the exception of other third-party libraries/code which may be included under compatible licenses.

Copyright (c) 2026 The Hammy Contributors
