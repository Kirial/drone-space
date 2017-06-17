#include "ofMain.h"
#include "settings.h"
#include "DroneRoom.h"

WayPoint::WayPoint() {

  wirebox.node.setParent(node);
  wirebox.set(WAYPOINT_X, WAYPOINT_Y, WAYPOINT_Z);

}

void WayPoint::draw() {

  //ofSetColor(color);
  wirebox.draw();
  node.draw();

}

QR::QR() {

  plane.rotate(90,1,0,0);
  plane.rotate(90,0,0,1);
  plane.set(QR_SIZE_Y, QR_SIZE_X);
  plane.setParent(node);

}

void QR::draw() {

  node.draw();
  plane.draw();

}

void QR::setPosition(float x, float y, float z) {

  node.setPosition(x,y,z);

}

Hoop::Hoop() {

  radius = HOOP_RADIUS_C;
  orientation = ofVec3f(0,0,1);

  // Hoop
  hoop.rotate(90,0,0,1);
  hoop.set(radius, HOOP_THICKNESS,false);
  hoop.setParent(node);

  // Stand
  //stand.setParent(node);

  // Hitbox
  hitbox.set(DRONE_SAFETYDISTANCE*2, (DRONE_SAFETYDISTANCE+radius)*2, (DRONE_SAFETYDISTANCE+radius)*2);
  hitbox.node.setParent(node);

  // Passage
  passage.set(HOOP_PASSAGE_X, HOOP_PASSAGE_Y, HOOP_PASSAGE_Z);
  passage.node.setParent(node);

  // Entry
  entrypoint.node.move(HOOP_WAYPOINT_OFFSET,0,0);
  entrypoint.node.setParent(node);

  // Exit
  exitpoint.node.move(-HOOP_WAYPOINT_OFFSET,0,0);
  exitpoint.node.setParent(node);

}

void Hoop::draw() {

  node.draw();
  hoop.draw();
  stand.draw();
  hitbox.draw();
  passage.draw();
  entrypoint.draw();
  exitpoint.draw();

}

void Hoop::setRadius(int _radius) {

  radius = _radius;
  hoop.set(radius, HOOP_THICKNESS,false);

}

void Hoop::setOrientation(ofVec3f _orientation) {

  float angle = orientation.angle(_orientation);

  orientation = _orientation;

  node.rotate(angle,0,1,0);

}

ofVec3f Hoop::getEntryPosition() {
  return entrypoint.node.getGlobalPosition();
}

ofVec3f Hoop::getExitPosition() {
  return exitpoint.node.getGlobalPosition();
}

ofVec3f Hoop::getPosition() {
  return node.getGlobalPosition();
}

void Hoop::setPosition(float x, float y, float z) {

  node.setPosition(x,y,z);
  stand.setPosition(x,(y-radius)/2,z);
  stand.set(HOOP_THICKNESS,y-radius);

}

LandingPlatform::LandingPlatform() {

  // Plane
  platform.rotate(90,1,0,0);
  platform.set(LANDINGPLATFORM_X, LANDINGPLATFORM_Z);
  platform.setParent(node);

  // Wirebox
  waypoint.node.move(0,LANDINGPLATFORM_POS_Y,0);
  waypoint.node.setParent(node);

}

void LandingPlatform::draw() {

  node.draw();
  platform.draw();
  waypoint.draw();

}

Room::Room() {

  wirebox.node.move(0,ROOM_SIZE_Y/2,0);
  hitbox.node.move(0,ROOM_SIZE_Y/2,0);
  wirebox.node.setParent(node);
  hitbox.node.setParent(node);
  wirebox.set(ROOM_SIZE_X,ROOM_SIZE_Y,ROOM_SIZE_X);
  hitbox.set(
    ROOM_SIZE_X-2*DRONE_SAFETYDISTANCE,
    ROOM_SIZE_Y-2*DRONE_SAFETYDISTANCE,
    ROOM_SIZE_Z-2*DRONE_SAFETYDISTANCE
  );

}

void Room::draw() {

  node.draw();
  wirebox.draw();
  hitbox.draw();

}

DroneRoom::DroneRoom() {

  room.node.setParent(node);

  // Landing Platform

  landingplatform.node.setParent(node);
  landingplatform.node.move(LANDINGPLATFORM_POS_X,0,LANDINGPLATFORM_POS_Z);

  // Hoop

  if(!HOOP_RANDOM) {

    hoops[0].setPosition(HOOP_A_X,HOOP_A_Y,HOOP_A_Z);
    hoops[1].setPosition(HOOP_B_X,HOOP_B_Y,HOOP_B_Z);
    hoops[2].setPosition(HOOP_C_X,HOOP_C_Y,HOOP_C_Z);
    hoops[3].setPosition(HOOP_D_X,HOOP_D_Y,HOOP_D_Z);

  }

  for(int i = 0; i < HOOP_COUNT; i++) {

    if(HOOP_RANDOM) {

      int aRand = ofRandom(0,359);

      int xRand = ofRandom(-449,449);
      int yRand = ofRandom(101,299);
      int zRand = ofRandom(-449,449);

      hoops[i].setPosition(xRand,yRand,zRand);

      hoops[i].node.rotate(aRand,0,1,0);

    }

    hoops[i].number = i;

    hoops[i].node.setParent(node);

  }

  // QR

  QRs[0].setPosition(QR_A_X,QR_A_Y,QR_A_Z);
  QRs[1].setPosition(QR_B_X,QR_B_Y,QR_B_Z);
  QRs[2].setPosition(QR_C_X,QR_C_Y,QR_C_Z);
  QRs[3].setPosition(QR_D_X,QR_D_Y,QR_D_Z);

  QRs[0].node.setParent(node);
  QRs[1].node.setParent(node);
  QRs[2].node.setParent(node);
  QRs[3].node.setParent(node);

}

void DroneRoom::draw() {

  ofSetColor(ofColor::black);

  node.draw();
  room.draw();
  landingplatform.draw();

  for(int i = 0; i < hoopCount; i++) {

    hoops[i].draw();

  }

  for(int i = 0; i < qrCount; i++) {

    QRs[i].draw();

  }
}

ofVec3f DroneRoom::getLandingWaypoint() {
  return landingplatform.waypoint.node.getGlobalPosition();
}

ofVec3f DroneRoom::getLandingPlatform() {
  return landingplatform.node.getGlobalPosition();
}
