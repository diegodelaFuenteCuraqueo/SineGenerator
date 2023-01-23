//
//  WaveForm.cpp
//  SineGenerator
//
//  Created by Diego Ignacio de la Fuente Curaqueo on 22-01-23.
//
#include <iostream>
#include <cmath>
#include "WaveForm.hpp"
using namespace std;

WaveForm::WaveForm (int sr, double freq, int amp)
{
  cout << " ~ WaveForm : creating waveform ~" << endl;
  sampleRate = sr;
  frequency = freq;
  amplitude = amp;
}

int WaveForm::sinewave (int index)
{
  double sample = sin(2 * M_PI * frequency * index / sampleRate);
  int normalizedSample = (int)(sample * amplitude);
  return normalizedSample;
}
