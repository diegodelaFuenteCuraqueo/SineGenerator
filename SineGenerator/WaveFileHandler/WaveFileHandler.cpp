#include <iostream>
#include <fstream>
#include <cmath>
#include "WaveFileHandler.h"
#include "../WaveForm/WaveForm.hpp"
using namespace std;

struct fileNotOpenException : public exception {
  const char * what () const throw () {
    return "\n Couldn't open the file! \n Check path or filename";  }
};


struct writeOnFileException : public exception {
  const char * what () const throw () {
    return "\n An error ocurred while writing on the file! \n";
  }
};

WaveFileHandler::WaveFileHandler(int sr, double dur) {
  sampleRate = sr;
  duration = dur;
  numChannels = 1;
  fileName = "sine_wave";
}

WaveFileHandler::~WaveFileHandler() { }

int WaveFileHandler::getTotalSamples() {
  return duration * sampleRate;
}

void WaveFileHandler::writeWaveFileHeader() {
  cout << " ~ Wave File : writing wav header... ~" << endl;

  // Open wav file for writing
  ofstream outFile(fileName + ".wav", ios::binary);
  if (!outFile.is_open()) throw fileNotOpenException();

  try {
    outFile.write("RIFF", 4);
    int fileSize = 36 + getTotalSamples() * 3;
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
    short bitsPerSample = BITDEPTH;
    outFile.write((char*)&bitsPerSample, 2);

    // Write data chunk into wav file
    outFile.write("data", 4);
    int dataChunkSize = getTotalSamples() * 3;
    outFile.write((char*)&dataChunkSize, 4);
    
    if (outFile.fail()) throw writeOnFileException();
  } catch (writeOnFileException e) {
    cerr << e.what() << " Error: couldn't write wav file Header." << endl;
    exit(1);
  }
}

void WaveFileHandler::writeSinewave(double frequency) {
  cout << " ~ Wave File : writing Sinewave... (" + to_string(frequency) + " hz, "+to_string(sampleRate)+" sr)" << endl;

  ofstream outFile(fileName + ".wav", ios::binary | ios::app);
  if (!outFile.is_open()) throw fileNotOpenException();

  WaveForm sineMaker(sampleRate, frequency, AMPLITUDE);
  
  try {
    // Write sine wave samples one by one
    for (int i = 0; i < getTotalSamples(); i++) {
      int sample = sineMaker.sinewave(i);
      outFile.write((char*)&sample, 3);
      if (outFile.fail()) throw writeOnFileException();
    }
  } catch (writeOnFileException e) {
    cerr << e.what() << " Error: couldn't write sample data." << endl;
    exit(1);
  }
  // Close the file
  cout << " ~ Wave File : "+to_string(getTotalSamples())+" samples saved. Closing file ~" << endl;
  outFile.close();
}
