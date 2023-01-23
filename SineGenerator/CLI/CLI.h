#ifndef CLI_hpp
#define CLI_hpp

#endif /* CLI_hpp */
#include <stdio.h>
#include <iostream>

/*
  This class is used to handle the command line interface.
  It also performs simple validation on the user input.
*/
class CLI
{
  private:
    double validateDouble();

  public:

    /*
      Constructor (prints welcome message).
    */
    CLI();

    /*
      This function asks the user for the duration of the wav file.
      @return <double>: the duration of the wav file in seconds.
    */
    double askForDuration();

    /*
      This function asks the user for the frequency of the wav file.
      @return <double>: the frequency of the wav file in hz.
    */
    double askForFrequency();

    void end();
};
