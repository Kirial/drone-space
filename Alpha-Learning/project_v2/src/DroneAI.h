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
  int end = false;
};

struct HoopDistance {

  float distToTrajectory;
  float distToOrigin;
  int intDist;
  int n;

};

class DroneAI {

public:

  DroneAI(Drone *_drone, DroneRoom *_droneroom, DroneControl *_dronecontrol);

  void update();

  void draw();

private:

  Drone *drone;
  DroneRoom *droneroom;
  DroneControl *dronecontrol;

  //

  void droneStart();
  void droneTakeoff();
  void droneLoop();
  void droneLanding();
  void droneLand();

  // Trajectory Functions
  int originalTrajectory();
  void optimizeTrajectory(Trajectory *currentPtr, Trajectory *headPtr, int *count);
  void startAllTrajectories();

  // Draw
  void drawTakeoffTrajectory();
  void drawLoopTrajectory();
  void drawLandingTrajectory();

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

  // --- Anti Collision ---

  ofVec3f antiCollision();

  // --- Real Drone Functions ---

  // --- Virtual Drone Functions ---

  int move(float x, float y, float z);
  int turn(float a);
  int setPosition(float x, float y, float z);
  int setTurn(float a);
  int setDroneSensorHeight(float h);

};

#endif /* end of include guard: DRONEAI_H */
