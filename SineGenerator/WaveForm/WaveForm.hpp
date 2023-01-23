//
//  WaveForm.hpp
//  SineGenerator
//
//  Created by Diego Ignacio de la Fuente Curaqueo on 22-01-23.
//

#ifndef WaveForm_hpp
#define WaveForm_hpp

#include <stdio.h>

#endif /* WaveForm_hpp */

/*
  This class used to calculate waveforms.
*/
class WaveForm {
  private:
    int sampleRate;
    double frequency;
    int amplitude;

  public:
    /*
      Object Constructors:
      @param sr <int>: the base sample rate of the waveform.
      @param freq <double>: the frequency of the waveform
      @param amp <int>: the amplitude of the waveform.
    */
    WaveForm(int sr, double freq, int amp);
    WaveForm();

    //setters
    void setAmplitude(int amp);
    void setFrequency(double freq);
    void setSampleRate(int sr);

    //getters
    int getAmplitude();
    double getFrequency();
    int getSampleRate();

    /*
      This function calculates a simple sinewave.
      @param index <int>: the index of the sample.
      @return <int>: the value of the sinewave at the given index.
    */
    int sinewave(int index);

  /* TODO:
     void squarewave(double frequency);
     void phasorwave(double frequency);
     ...and so
   */
};
