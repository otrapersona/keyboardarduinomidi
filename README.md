# keyboardarduinomidi

Through Arduino, use a USB keyboard as a MIDI controller for a music device.

Tested on Genius SlimStar 130 (GK-150001) keyboard, Arduino UNO R3 board, Volca Kick analogue kick generator (firmware v 1.05, date 2019-09-10).

Note: I learned *some* music theory in middle school, I'm sorry for any music crimes.

## Setup

### Libraries

You'll need the `MIDI` library by Francois Best.\
It's downloaded through the Arduino IDE library manager.

### Keyboard-Arduino connection

[Source](https://create.arduino.cc/projecthub/michalin70/connect-a-usb-keyboard-with-an-arduino-50c077 "Connect a USB Keyboard with an Arduino - Arduino Project Hub") and [source](https://create.arduino.cc/projecthub/Ahmedebeed555/connect-arduino-uno-to-usb-keyboard-2f01f8 "Connect Arduino UNO to USB Keyboard - Arduino Project Hub")

| Keyboard | arduino | Resistor |
|----------|---------|----------|
| 5v       | 5v      | no       |
| Gnd      | Gnd     | no       |
| Data+    | 7       | 10k Ω    |
| Data-    | 6       | 10k Ω    |

### MIDI-Arduino connection

[Source](https://docs.arduino.cc/built-in-examples/communication/Midi "MIDI Note Player | Arduino Documentation | Arduino Documentation")

| MIDI | Arduino | Resistor	|
|------|---------|----------|
| 5    | 1       | 220 Ω    |
| 2    | Gnd     | no       |
| 4    | 5V      | 220 Ω    |

## Functions

### Music keyboard

[Source](https://newt.phys.unsw.edu.au/jw/notes.html "Note names, MIDI numbers and frequencies")

The next section (Octave selector) addresses changing octave/pitch.

| Key | Note       | Note alt name     |
|-----|------------|-------------------|
| z   | do         | C                 |
| s   | re♭ / do♯  | D minor / C mayor |
| x   | re         | D                 |
| d   | mi♭ / re♯  | E minor / D mayor |
| C   | mi         | E                 |
| V   | fa         | F                 |
| G   | sol♭ / fa♯ | G minor / C mayor |
| B   | sol        | G                 |
| H   | la♭ / sol♯ | A minor / C mayor |
| N   | la         | A                 |
| J   | si♭ / la♯  | B minor / C mayor |
| M   | si         | B                 |

### Octave selector

Default = 1. You might want to switch to octave 4 first, [source](https://en.wikipedia.org/wiki/Octave "Octave - Wikipedia").

Press one of these keys* to change the octave of the keyboard (pitch?).\
*On the number row, not the pad (decided on this for tenkeyless compatibility).

| key | octave |
|-----|--------|
| 0   | 0      |
| 1   | 1      |
| 2   | 2      |
| 3   | 3      |
| 4   | 4      |
| 5   | 5      |
| 6   | 6      |
| 7   | 7      |
| 8   | 8      |
