#ifndef DRONEROOM_H
#define DRONEROOM_H

#include "ofMain.h"
#include "ofxNBxyz/ofxNBxyzWirebox.h"

class WayPoint {

public:

  WayPoint();

  void draw();

  ofNode node;

private:

  Wirebox wirebox;
  ofColor color = ofColor::black;

};

class QR {

public:

  QR();

  void draw();

  void setPosition(float x, float y,float z);

  ofNode node;

private:

  ofPlanePrimitive plane;

};

class Hoop {

public:

  Hoop();

  void draw();

  void setPosition(float x,float y,float z);

  ofNode node;

private:

  ofCylinderPrimitive hoop;
  ofCylinderPrimitive stand;

  Wirebox hitbox;
  Wirebox passage;

  WayPoint entrypoint;
  WayPoint exitpoint;

};

class LandingPlatform {

public:

  LandingPlatform();

  void draw();

  ofNode node;

private:

  ofPlanePrimitive platform;

  WayPoint point;

};

class Room {

public:

  Room();

  void draw();

  ofNode node;

private:

  Wirebox wirebox;
  Wirebox hitbox;

};

class DroneRoom {

public:

  DroneRoom();

  void draw();

  ofNode node;

private:

  Room room;
  LandingPlatform landingplatform;

  Hoop hoops[16];
  int hoopCount;

  QR QRs[4];
  int qrCount;

};

#endif /* end of include guard: DRONEROOM_H */
