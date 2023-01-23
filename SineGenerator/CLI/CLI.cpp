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

double CLI::askForDuration () {
  cout << " · Enter duration (seconds):" << endl;
  double duration = CLI::validateDouble();
  while (duration <= 0) {
    cout << "Duration must be greater than 0, please try again: " << endl;
    duration = CLI::validateDouble();
  }
  return duration;
}

double CLI::askForFrequency () {
  cout << " · Enter frequency (Hz):" << endl;
  double frequency = CLI::validateDouble();
  while (frequency <= 0) {
    cout << "Frequency must be greater than 0, please try again: " << endl;
    frequency = CLI::validateDouble();
  }
  return frequency;
}
