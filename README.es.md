# keyboardarduinomidi

## [(Readme in English)](https://github.com/otrapersona/keyboardarduinomidi/blob/main/README.md)

A través de Arduino, usa un teclado USB de computadora como controlador MIDI para un instrumento musical.

Probado con teclado Genius SlimStar 130 (GK-150001), placa Arduino UNO R3, generador kick análogo Volca Kick (firmware v 1.05, fecha 2019-09-10).

Nota: Aprendí *algo* de teoría musical en secundaria, disculpen cualquier crimen musical.

## Preparación

### Librerías

Se necesita la librería `MIDI` de Francois Best.\
Está disponible en el administrador de librerías del IDE de Arduino.

### Conexión Teclado-Arduino

[Fuente](https://create.arduino.cc/projecthub/michalin70/connect-a-usb-keyboard-with-an-arduino-50c077 "Connect a USB Keyboard with an Arduino - Arduino Project Hub") y [fuente](https://create.arduino.cc/projecthub/Ahmedebeed555/connect-arduino-uno-to-usb-keyboard-2f01f8 "Connect Arduino UNO to USB Keyboard - Arduino Project Hub").

| Teclado  | Arduino | Resistencia |
|----------|---------|-------------|
| 5v       | 5v      | no          |
| Gnd      | Gnd     | no          |
| Data+    | 7       | 10k Ω       |
| Data-    | 6       | 10k Ω       |

### Conexión MIDI-Arduino

[Fuente](https://docs.arduino.cc/built-in-examples/communication/Midi "MIDI Note Player | Arduino Documentation | Arduino Documentation").

| MIDI | Arduino | Resistencia |
|------|---------|-------------|
| 5    | 1       | 220 Ω       |
| 2    | Gnd     | no          |
| 4    | 5V      | 220 Ω       |

## Funciones

### Teclado musical

[Fuente](https://newt.phys.unsw.edu.au/jw/notes.html "Note names, MIDI numbers and frequencies").

La siguiente sección (selector de octava) permite cambiar la octava/tono.

| Tecla | Nota     | Nota otro nombre  |
|-------|------------|-------------------|
| z     | do         | C                 |
| s     | re♭ / do♯  | D menor / C mayor |
| x     | re         | D                 |
| d     | mi♭ / re♯  | E menor / D mayor |
| C     | mi         | E                 |
| V     | fa         | F                 |
| G     | sol♭ / fa♯ | G menor / C mayor |
| B     | sol        | G                 |
| H     | la♭ / sol♯ | A menor / C mayor |
| N     | la         | A                 |
| J     | si♭ / la♯  | B menor / C mayor |
| M     | si         | B                 |

### Selector de octava

Default = 1. Tal ves quieras comenzar con la octava 4, [fuente](https://en.wikipedia.org/wiki/Octave "Octave - Wikipedia").

Presiona una de estas teclas* para cambiar la octava (tono?).\
*En la fila de números, no el teclado numérico (decidí esto por compatibilidad con teclados cortos).

| Tecla | Octava |
|-------|--------|
| 0     | 0      |
| 1     | 1      |
| 2     | 2      |
| 3     | 3      |
| 4     | 4      |
| 5     | 5      |
| 6     | 6      |
| 7     | 7      |
| 8     | 8      |
