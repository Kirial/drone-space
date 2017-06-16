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

  // ---

private:

};

#endif /* end of include guard: DRONECONTROL_H */
