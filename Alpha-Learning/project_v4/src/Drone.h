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
  FlightMode getFlightMode();
  void setDroneMode(DroneMode _dronemode);
  DroneMode getDroneMode();

  void toggleManualMode();

  // Control

  void move(ofVec3f vector);
  void turn(float a);

  float getSpeed();
  float getRotationSpeed();

  ofNode node;

  // What the drone sees

  void addHoop(int x, int y, int h, int n);
  void resetHoops();

  void addQR(int x, int y, int h, int n);
  void resetQRs();

private:

  // View

  void drawView();
  void drawViewedHoops();
  void drawProjectedHoops();
  void drawViewedQRs();
  void drawProjectedQRs();

  float viewOffsetX;
  float viewOffsetY;
  float viewOffsetZ;

  int seenHoopsCount;
  int seenQRsCount;

  ofCylinderPrimitive viewedHoops[HOOP_COUNT];
  ofCylinderPrimitive projectedHoops[HOOP_COUNT];
  int viewedHoopsNumber[HOOP_COUNT];

  ofPlanePrimitive viewedQRs[HOOP_COUNT+QR_COUNT];
  ofPlanePrimitive projectedQRs[HOOP_COUNT+QR_COUNT];
  int viewedQRsNumber[HOOP_COUNT+QR_COUNT];

  ofNode view[4];

  // Appearance

  ofBoxPrimitive box;

  // Movement

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
