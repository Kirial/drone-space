#ifndef USERINTERFACE_CPP
#define USERINTERFACE_CPP

#include "userinterface.h"
#include <iostream>


UserInterface::UserInterface() {

  string = 'C';

  cout << "Setting up user interface." << "\n\r";

  cout << string << "\n\r";

  cout << "Done!" << "\n\r";

}

void UserInterface::init() {

  string = 'I';

  cout << "Initializing user interface." << "\n\r";

  cout << string << "\n\r";

  cout << "Done!" << "\n\r";

}

void UserInterface::draw() {

  cout << string << "\n\r";

  cout << "Drawing." << "\n\r";

  string = 'D';

}

void UserInterface::control() {

  cout << string << "\n\r";

  cout << "Controlling." << "\n\r";

  string = 'J';

}

void UserInterface::cli() {

  cout << string << "\n\r";

  cout << "CLIing." << "\n\r";

  string = 'i';

}

void UserInterface::exit() {

  cout << string << "\n\r";

  cout << "Exit." << "\n\r";

}


#endif
