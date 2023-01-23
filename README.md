# SineGenerator
By Diego de la Fuente
## Description
A simple C++ CLI Soundwave genetaror that can store the data in a wav file. It only requires the **duration** and the **frequency** of the wave.<BR>
*(By default, the BitDepth = 24 and sample rate = 48000)*

## Basic Usage

After building and running the app (using g++ or Xcode). You'll get a welcome message:

```
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
·   ·   ·  Sinewave wav file generator  ·   ·   ·
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 · Enter duration (seconds):
```

Both Duration and Frequency can be a greater-than-zero decimal value.

```
 · Enter frequency (Hz):
```

After that, a wave file is created with the name `sine_wave.wav` in the folder where the app was called.
In this example the duration is 2 seconds and the frequency is 2000 Hz.

```
 ~ Wave File : writing wav header... ~
 ~ Wave File : writing Sinewave... (2000.000000 hz, 48000 sr)
 ~ WaveForm : creating waveform ~
 ~ Wave File : 240000 samples saved. Closing file ~
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
```