#ifndef WaveFileHandler_hpp
#define WaveFileHandler_hpp

#endif /* WaveFileHandler_hpp */

#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

/*
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
    /*
      Object Constructor:
      @param sr <int>: the sample rate of the wav file.
      @param dur <double>: the duration of the wav file in seconds.
    */
    WaveFileHandler(int sr, double dur);
    WaveFileHandler();

    //setters
    void setSampleRate(int sr);
    void setDuration(double dur);
    void setFileName(std::string name);
    void setNumChannels(int num);

    //getters
    int getTotalSamples();
    int getSampleRate();
    double getDuration();
    std::string getFileName();
    int getNumChannels();

    /*
      This function writes the header of the wav file.
    */
    void writeWaveFileHeader();

    /*
      This function writes the data to the wav file.
      @param frequency <double>: the frequency of the wav file in hz.
    */
    void writeSinewave(double frequency);

};
