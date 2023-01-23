//
//  main.cpp
//  SineGenerator
//
//  Created by Diego Ignacio de la Fuente Curaqueo on 22-01-23.
//

#include <iostream>
#include "SaveWaveInWav/SaveWaveInWav.h"
#include "CLI/CLI.h"


using namespace std;

int main(int argc, const char * argv[]) {

  // a simple cli to get user input
  CLI cli;
  double duration = cli.askForDuration();
  double frequency = cli.askForFrequency();

  /*
   The function that creates an audio wave file with pure sinusoidal sound.
  */
  SaveWaveInWav(duration, frequency);

  cli.end();
  return 0;
}
