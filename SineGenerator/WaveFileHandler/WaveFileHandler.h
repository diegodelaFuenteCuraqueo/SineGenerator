#ifndef WaveFileHandler_hpp
#define WaveFileHandler_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

#define AMPLITUDE 8388607
#define BITDEPTH 24

/**
  This class is used to handle a wav file.
  It creates the header and writes the data to the file.
*/
class WaveFileHandler
{
  private:
    int sampleRate;
    double duration;
    int numChannels;
    std::string fileName;

  public:
    /**
    Object Constructor:
     - Parameters:
        - sr : the sample rate of the wav file. <int>
        - dur : the duration of the wav file in seconds. <double>
    */
    WaveFileHandler(int sr, double dur);
    ~WaveFileHandler();

    /// - Returns <int>: total number of samples (sampleRate * duration)
    int getTotalSamples();
    
    /// This function writes the header of the wav file.
    void writeWaveFileHeader();

    /**
    This function writes the data to the wav file.
     - Parameters:
        - frequency : the frequency of the wav file in hz <double>.
    */
    void writeSinewave(double frequency);

};

#endif /* WaveFileHandler_hpp */
