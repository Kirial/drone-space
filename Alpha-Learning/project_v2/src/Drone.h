 #ifndef DRONE_H
#define DRONE_H

#include "ofMain.h"

enum DroneMode {READY, HOLD, AUTONOMOUS, MANUAL, LANDED};

enum FlightMode {FAST, NORMAL, STEADY, TAKEOFF, LANDING, NOTFLYING, INSANE, LUDICROUS};

void printFlightMode(FlightMode flightmode);

class Drone {

public:

  Drone();

  void draw();
  void update();

  // View

  void drawView();

  // Godlike

  ofVec3f setPosition(ofVec3f position); // Return difference.
  ofVec3f getPosition(); // Return current position.

  // Autonomous

  ofVec3f setDestination(ofVec3f _destination); // Set new destination.
  ofVec3f getDestination(); // Return diffence vector.
  float getDestinationDistance();
  int onPoint();

  // Set DroneMode(Speed) and FlightMode

  void setFlightMode(FlightMode _flightmode);
  int getSpeed();
  FlightMode getFlightMode();
  void setDroneMode(DroneMode _dronemode);
  DroneMode getDroneMode();

  ofNode node;

private:

  ofNode view[4];

  ofBoxPrimitive box;

  ofNode forward;
  ofNode direction;

  ofVec3f destination;
  ofVec3f destinationOffset;

  float speed;

  FlightMode flightmode;
  DroneMode dronemode;

  float newAngle, angle, angleOffset;

};

#endif /* end of include guard: DRONE_H */
