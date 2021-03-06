#ifndef DRONECONTROL_H
#define DRONECONTROL_H

#include "ofMain.h"
#include "Drone.h"
#include "DroneRoom.h"

class DroneControl {

public:

  DroneControl(Drone *drone);

  // ---

  // --- RPC Functions ---

  // CV - Hoops
  int askHoops();
  int askHoopX(int n); // X position on camera
  int askHoopY(int n); // Y position on camera
  int askHoopH(int n); // Vertical Radius
  int askHoopW(int n); // Horizontal Radius

  // CV - QR
  int askQRs();
  int askQRX(int n);
  int askQRY(int n);
  int askQRH(int n);
  int askQRW(int n);

  // Drone Sensors
  int askHeight();
  int askTrueAngle();

  // Drone Instructions (True, ready to move, false can't move now)
  int instruction(float x, float y, float z, float a);
  int takeoff();
  int land();

  // Manual Control

  void instruct();

  int upToggle(bool keyPressed); // Space
  int downToggle(bool keyPressed); // Shift

  // XY Basic Control
  int forwardToggle(bool keyPressed); // w W
  int backwardToggle(bool keyPressed); // s S

  int strafeLeftToggle(bool keyPressed); // A a
  int strafeRightToggle(bool keyPressed); // D d

  int turnLeftToggle(bool keyPressed); // E e
  int turnRightToggle(bool keyPressed); // Q q

  // Set Mode

  void toggleManualMode(bool keyPressed);

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

  FlightMode savedflightmode;
  DroneMode saveddronemode;

};

#endif /* end of include guard: DRONECONTROL_H */
