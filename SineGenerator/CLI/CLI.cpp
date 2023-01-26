#include "CLI.h"

using namespace std;

struct inputException : public exception {
  const char * what () const throw () {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return "Invalid input value ";
  }
};

struct wrongValueException : public exception {
  const char * what () const throw () {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return "Value must be greater than 0";
  }
};

CLI::CLI () {
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  cout << "·   ·   ·  Sinewave wav file generator  ·   ·   ·" << endl;
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void CLI::end () {
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

double CLI::validateDouble () {
  double input;
  try {
    cin >> input;
    if (cin.fail()) {
      throw inputException();
    } else if (input <= 0) {
      throw wrongValueException();
    };

  } catch (inputException& e) {
    cout << e.what() << " Please try again: " << endl;
    input = CLI::validateDouble();
  } catch (wrongValueException& e) {
    cout << e.what() << " Please try again: " << endl;
    input = CLI::validateDouble();
  }
  return input;
}

double CLI::validateFreq () {
  double freq = CLI::validateDouble();
  while (freq >= 24000) {
    cout << "The maximum frequency is 24khz, to avoid aliasing try a value between 0 - 24,000" << endl;
    freq = CLI::validateFreq();
  }
  return freq;
}

double CLI::askForDuration () {
  cout << " · Enter duration (seconds):" << endl;
  return CLI::validateDouble();
}

double CLI::askForFrequency () {
  cout << " · Enter frequency (Hz):" << endl;
  return CLI::validateFreq();
}
