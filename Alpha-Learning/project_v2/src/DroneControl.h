#ifndef DRONECONTROL_H
#define DRONECONTROL_H

#include "ofMain.h"
#include "Drone.h"
#include "DroneRoom.h"

class DroneControl {

public:

  DroneControl();

  // ---

  // --- RPC Functions ---

  // CV - Hoops
  int askHoop();
  int askHoopX(int n); // X position on camera
  int askHoopY(int n); // Y position on camera
  int askHoopRa(int n); // Vertical Radius
  int askHoopRb(int n); // Horizontal Radius

  // CV - QR
  int askQR();
  int askQRX(int n);
  int askQRY(int n);

  // Drone Sensors
  int askHeight();
  int askMagnetometerOrientation();

  // Drone Instructions (True, ready to move, false can't move now)
  int tellMove(int x, int y, int z);
  int tellTurn(int a);
  int tellSetSpeed(int ms);
  int tellForceMove(int x, int y, int z);
  int tellForceTurn(int a);
  int tellForceSetSpeed(int ms);

  // ---

private:

};

#endif /* end of include guard: DRONECONTROL_H */
