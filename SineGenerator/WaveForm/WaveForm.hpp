//
//  WaveForm.hpp
//  SineGenerator
//
//  Created by Diego Ignacio de la Fuente Curaqueo on 22-01-23.
//

#ifndef WaveForm_hpp
#define WaveForm_hpp

#include <stdio.h>

/// This class used to calculate waveforms.
class WaveForm {
  private:
    int sampleRate;
    double frequency;
    int amplitude;

  public:
    /**
     Object constructor
      - Parameters:
       - sr <int>: samplerate of the waveform.
       - freq <double>: the frequency of the waveform
       - amp <int>: the amplitude of the waveform.
    */
    WaveForm(int sr, double freq, int amp);
    ~WaveForm();

    /**
    This function calculates a simple sinewave.
      - Parameters:
        - index: the index of the sample.
      - Returns: the value of the sinewave at the given index.
    */
    int sinewave(int index);

};

#endif /* WaveForm_hpp */
