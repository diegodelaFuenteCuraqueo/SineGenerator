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

WaveForm::WaveForm() {}

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
  int normalizedSample = static_cast<int>(sample * amplitude);
  return normalizedSample;
}

void WaveForm::setSampleRate(int sr) { //validaciones
  sampleRate = sr;
}

void WaveForm::setFrequency(double freq) { //validaciones
  frequency = freq;
}

void WaveForm::setAmplitude(int amp) { //validaciones
  amplitude = amp;
}

int WaveForm::getSampleRate() {
  return sampleRate;
}

double WaveForm::getFrequency() {
  return frequency;
}

int WaveForm::getAmplitude() {
  return amplitude;
}
