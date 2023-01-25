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

WaveForm::WaveForm (int sampleRate, double frequency, int amplitude) :
  sampleRate(sampleRate),
  frequency(frequency),
  amplitude(amplitude)
{
  cout << " ~ WaveForm : creating waveform ~" << endl;
}

int WaveForm::sinewave (int index)
{
  double sample = sin(2 * M_PI * frequency * index / sampleRate);
  int normalizedSample = static_cast<int>(sample * amplitude);
  return normalizedSample;
}

WaveForm::~WaveForm() { }
