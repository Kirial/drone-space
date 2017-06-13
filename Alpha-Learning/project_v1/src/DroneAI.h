#ifndef DRONEAI_H
#define DRONEAI_H

#include "ofMain.h"
#include "settings.h"
#include "Drone.h"
#include "DroneRoom.h"
#include "DroneControl.h"

// Waypoint

// Trajectory

// Path

class DroneAI {

public:

  DroneAI();

  void setup(Drone *drone, DroneRoom *droneroom, DroneControl *dronecontrol);

  // Update

  // Draw Collisions

  void drawAntiCollision();
  void drawRoomCollision();
  void drawHoopCollision();

  // Draw paths

  void drawProjection(); // Future
  void drawTrail(); // Past

  void drawHoopPassage();
  void drawLandingZone();

private:

  Drone *drone;
  DroneRoom *droneroom;
  DroneControl *dronecontrol;

};

#endif /* end of include guard: DRONEAI_H */
