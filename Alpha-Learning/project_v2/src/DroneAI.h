#ifndef DRONEAI_H
#define DRONEAI_H

#include "ofMain.h"
#include "Drone.h"
#include "DroneRoom.h"
#include "DroneControl.h"

struct Trajectory {
  ofVec3f point;
  Trajectory *next;
  Trajectory *prev;
  FlightMode flightmode;
};

class DroneAI {

public:

  DroneAI(Drone *_drone, DroneRoom *_droneroom, DroneControl *_dronecontrol);

  int update();

  void optimizeTrajection(Trajectory *currentPtr, Trajectory *headPtr, int *count);

  int antiCollision();

  void sortHoops();

  int originalTrajectory();

  void draw();
  void drawTakeoffTrajectory();
  void drawLoopTrajectory();
  void drawLandingTrajectory();

private:

  Drone *drone;
  DroneRoom *droneroom;
  DroneControl *dronecontrol;

  // Trajectory Functions

  // General Trajectory Functions
  void startAllTrajectories();

  // Loop
  void startLoopTrajectory();
  int addLoopPoint(ofVec3f addPoint, FlightMode flight);
  int insertLoopPoint(ofVec3f addPoint, FlightMode flight);
  int completeLoopTrajectory();

  // Takeoff
  void startTakeoffTrajectory();
  int addTakeoffPoint(ofVec3f addPoint, FlightMode flight);
  int insertTakeoffPoint(ofVec3f addPoint, FlightMode flight);
  int finishTakeoffTrajectory();

  // Landing
  void startLandingTrajectory();
  int addLandingPoint(ofVec3f addPoint, FlightMode flight);
  int insertLandingPoint(ofVec3f addPoint, FlightMode flight);
  int finishLandingTrajectory();

  // Loop Trajectory

  Trajectory loopTrajectory[LOOP_TRAJECTORY_MAX]; // The Round
  Trajectory *loopHead;
  Trajectory *loopTail;
  Trajectory *loopCurrent;
  int loopTrajectoryCount = 0;

  // Landing / Takeoff Trajectory

  Trajectory landingwaypoint;

  Trajectory takeoffTrajectory[TAKEOFF_TRAJECTORY_MAX]; // Takeoff into the Round
  Trajectory *takeoffHead;
  Trajectory *takeoffTail;
  Trajectory *takeoffCurrent;
  int takeoffTrajectoryCount = 0;

  Trajectory landingTrajectory[LANDING_TRAJECTORY_MAX]; // Landing from anywhere in on the Round
  Trajectory *landingHead;
  Trajectory *landingTail;
  Trajectory *landingCurrent;
  int landingTrajectoryCount = 0;

};

#endif /* end of include guard: DRONEAI_H */
