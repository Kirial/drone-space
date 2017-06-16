 #ifndef DRONE_H
#define DRONE_H

#include "ofMain.h"

enum DroneMode {READY, HOLD, AUTONOMOUS, MANUAL, LANDED, TAKEOFF, LANDING};

enum FlightMode {NOTFLYING, STEADY, NORMAL, FAST, INSANE, LUDICROUS};

void printFlightMode(FlightMode flightmode);
void printDroneMode(DroneMode dronemode);

class Drone {

public:

  Drone();

  void draw();
  void update();
  void instruction();

  // Godlike

  ofVec3f setPosition(ofVec3f position); // Return difference.
  ofVec3f getPosition(); // Return current position.

  // Autonomous

  ofVec3f setDestination(ofVec3f _destination); // Set new destination.
  ofVec3f getDestination(); // Return diffence vector.
  ofVec3f getDirection();
  ofVec3f getDestinationOffset();
  float getDestinationDistance();
  float getAngleOffset();

  // Set DroneMode(Speed) and FlightMode

  void setFlightMode(FlightMode _flightmode);
  int getSpeed();
  FlightMode getFlightMode();
  void setDroneMode(DroneMode _dronemode);
  DroneMode getDroneMode();

  // Control

  void move(ofVec3f);
  void turn(float a);

  ofNode node;

private:

  void drawView();

  ofNode view[4];

  ofBoxPrimitive box;

  ofNode forward;
  ofNode direction;

  ofVec3f destination;
  ofVec3f destinationOffset;

  ofVec3f angleRotationDirection;

  float speed;

  FlightMode flightmode;
  DroneMode dronemode;

  float angleOffset;

};

#endif /* end of include guard: DRONE_H */
