#ifndef WaveFileHandler_hpp
#define WaveFileHandler_hpp

#include <stdio.h>

#endif /* WaveFileHandler_hpp */

#include <iostream>

/*
  This class is used to handle a wav file.
  It creates the header and writes the data to the file.
*/
class WaveFileHandler
{
  private:
    int sampleRate;
    double duration;
    int totalSamples;
    int numChannels;
    std::string fileName;

  public:

    /*
      Object Constructor:
      @param sr <int>: the sample rate of the wav file.
      @param dur <double>: the duration of the wav file in seconds.
    */
    WaveFileHandler(int sr, double dur);

    /*
      This function creates the header of the wav file.
    */
    void writeWaveFileHeader();

    /*
      This function writes the data to the wav file.
      @param frequency <double>: the frequency of the wav file in hz.
    */
    void writeSinewave(double frequency);
};
