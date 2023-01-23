#include "CLI.h"

using namespace std;

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
  cin >> input;
  while (cin.fail()) {
    cout << "Invalid value, please try again: " << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> input; // asks again...
  };
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
