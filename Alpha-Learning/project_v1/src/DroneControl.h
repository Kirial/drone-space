#ifndef DRONECONTROL_H
#define DRONECONTROL_H

#include "Drone.h"

class DroneControl {

public:

  DroneControl();

  void setup(Drone *drone);

  // UI Control
  int keyboard(int key, bool keyPressed);
  int noKeyPressed();

  // Drone Commands
  int command(Drone *drone);

  // Z Control
  int upToggle(bool keyPressed); // Space
  int downToggle(bool keyPressed); // Shift

  // XY Basic Control
  int forwardToggle(bool keyPressed); // w W
  int backwardToggle(bool keyPressed); // s S

  int strafeLeftToggle(bool keyPressed); // A a
  int strafeRightToggle(bool keyPressed); // D d

  int turnLeftToggle(bool keyPressed); // E e
  int turnRightToggle(bool keyPressed); // Q q

  /*

    // Z Control
    int up(); // Space
    int down(); // Shift

    // XY Basic Control
    int forward(); // w W
    int backward(); // s S

    int strafeLeft(); // A a
    int strafeRight(); // D d

    int turnLeft(); // E e
    int turnRight(); // Q q

    // XY Advanced Control
    int forwardStrafeLeft(); // WA wa
    int forwardStrafeRight(); // WD wd

    int backwardStrafeLeft(); // SA sa
    int backwardStrafeRight(); // SD sd

    int turnLeftForward(); // WQ wq
    int turnRightForward(); // WE we

    int leftSidewaysBackward(); // SQ sq
    int rightSidewaysBackward(); // SE se

    int strafeLeftTurnLeft(); // QA qa
    int strafeLeftTurnRight(); // QD qd

    int strafeRightTurnLeft(); // EA ea
    int strafeRightTurnRight(); // ED ed

  */

private:

  Drone *drone;

  int up; // Space
  int down; // Shift
  float upDownSpeed;

  int forward; // A a
  int backward; // S s
  float forwardBackwardSpeed;

  int turnLeft; // Q q
  int turnRight; // E e
  float turnLeftRightSpeed;

  int strafeLeft; // A a
  int strafeRight; // D d
  float strafeLeftRightSpeed;

};

#endif /* end of include guard: DRONECONTROL_H */
