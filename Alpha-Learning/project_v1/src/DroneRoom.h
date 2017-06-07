#ifndef _DRONEROOM_H
#define _DRONEROOM_H

#include "settings.h"
#include "ofxNBxyz.h"

struct QR {

  string string;
  int number;

  int zSize;
  int ySize;

  ofNode node;
  ofPlanePrimitive plane;

  ofColor wireColor = ofColor::purple;
  ofColor nodeColor = ofColor::purple;

};

struct Hoop {

  string string;
  int number;

  int radius;

  ofNode node; // Master node

  ofNode entrypoint;
  ofNode exitpoint;

  ofCylinderPrimitive hoop;
  ofCylinderPrimitive stand;
  Wirebox hitbox;
  Wirebox passage;
  QR qr;

  ofColor hitboxColor = ofColor::green;
  ofColor passageColor = ofColor::green;
  ofColor wireColor = ofColor::cyan;
  ofColor nodeColor = ofColor::cyan;

};

struct LandingArea {

  string string = "Landing Area.";

  int xSize = LANDINGAREA_X;
  int zSize = LANDINGAREA_Z;

  float xPosition = 4000;
  float zPosition = 4000;

  ofNode node;
  ofPlanePrimitive plane;
  Wirebox space;

  ofColor spaceColor = ofColor::green;
  ofColor wireColor = ofColor::green;
  ofColor nodeColor = ofColor::green;

};

struct Room {

  int xSize;
  int ySize;
  int zSize;

  float xPos;
  float yPos;
  float zPos;

  ofNode node;
  ofBoxPrimitive box;
  Wirebox hitbox;

  ofColor wireColor = ofColor::black;
  ofColor nodeColor = ofColor::black;

};

class DroneRoom {

public:

  DroneRoom();

  // QR
  int addQR(string string, ofNode inputnode, ofNode *parent);

  // Hoop
  int addHoop(string string, ofNode inputnode, ofNode *parent);
  int updateHoop(int n, ofNode node);

  // Landing Area
  int updateLandingArea();

  // Draw
  void draw();
  void drawRoom();
  void drawHoop(Hoop *hoop);
  void drawQR(QR *qr);
  void drawLandingArea();

  // Anti Collision

  Wirebox getRoomHitbox();

  // The Node

  ofNode node;

private:

  // Room

  Room room;

  // QR Codes

  int nQRs = 0;
  static const int maxQRs = 4;
  QR QRs[maxQRs];

  // Hoops

  int nHoops = 0;
  static const int maxHoops = 4;
  Hoop Hoops[maxHoops];


  // Landing Area

  LandingArea landingarea;

};

#endif /* end of include guard: DRONEROOM_H */
