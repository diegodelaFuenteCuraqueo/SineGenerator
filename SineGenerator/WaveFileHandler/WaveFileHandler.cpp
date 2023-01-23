#include <iostream>
#include <fstream>
#include <cmath>

#include "WaveFileHandler.h"
#include "../WaveForm/WaveForm.hpp"
using namespace std;


WaveFileHandler::WaveFileHandler (int sr, double dur) {
  sampleRate = sr;
  duration = dur;
  totalSamples = duration * sampleRate;
  numChannels = 1;
  fileName = "sine_wave";
}

void WaveFileHandler::writeWaveFileHeader() {
  cout << " ~ Wave File : creating... ~" << endl;

  // Open wav file for writing
  ofstream outFile(fileName + ".wav", ios::binary);

  // WAV HEADER
  outFile.write("RIFF", 4);
  int fileSize = 36 + totalSamples * 3;
  outFile.write((char*)&fileSize, 4);
  outFile.write("WAVE", 4);
  outFile.write("fmt ", 4);

  // audio settings data
  int formatChunkSize = 16;
  outFile.write((char*)&formatChunkSize, 4);
  short audioFormat = 1;
  outFile.write((char*)&audioFormat, 2);
  short numChannels = 1;
  outFile.write((char*)&numChannels, 2);
  outFile.write((char*)&sampleRate, 4);
  int byteRate = sampleRate * numChannels * 3;
  outFile.write((char*)&byteRate, 4);
  short blockAlign = numChannels * 3;
  outFile.write((char*)&blockAlign, 2);
  short bitsPerSample = 24;
  outFile.write((char*)&bitsPerSample, 2);

  // Write data chunk into wav file
  outFile.write("data", 4);
  int dataChunkSize = totalSamples * 3;
  outFile.write((char*)&dataChunkSize, 4);
}

void WaveFileHandler::writeSinewave(double frequency) {
  cout << " ~ Wave File : writingSinewave... ~" << endl;

  ofstream outFile(fileName + ".wav", ios::binary | ios::app);
  WaveForm sine(sampleRate, frequency, 8388607);

  // Write the sine wave samples
  for (int i = 0; i < totalSamples; i++) {
    int sample = sine.sinewave(i);
    outFile.write((char*)&sample, 3);
  }

  // Close the file
  cout << " ~ Wave File : closing file ~" << endl;
  outFile.close();
}