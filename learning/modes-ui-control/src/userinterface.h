#ifndef USERINTERFACE_H
#define USERINTERFACE_H

using namespace std;

struct AppMode {

  // Mode Name

  // Function pointer to initialise mode

  // Function pointer to exit mode

  // Function pointer to graphics // Run in "draw"

  // Function pointer to controls // Run in "update"

  // Function pointer to command line interface // Update???

};

class UserInterface {

public: // Used and changes by public.

  UserInterface();

  void init();
  void draw(); // Used in draw;
  void control(); // Used in update;
  void cli(); // Used in update (???);
  void exit();

private: // Can neither be used or seen by public.

  void uiChangeMode();

  AppMode mode;

protected: // Can be used by public, can't be changed by public.

  char string;

};

#endif
