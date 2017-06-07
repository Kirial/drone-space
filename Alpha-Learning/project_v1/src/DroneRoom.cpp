#include "ofMain.h"
#include "settings.h"
#include "DroneRoom.h"
#include "ofxNBxyz.h"

DroneRoom::DroneRoom() {

  node.setScale(SCALE);
  node.setPosition(0,0,0);

  room.node.setParent(node);
  room.node.move(0,DRONEROOM_Y/2,0);

  room.box.setParent(room.node);
  room.box.set(DRONEROOM_X,DRONEROOM_Y,DRONEROOM_Z);

  room.hitbox.node.setParent(room.node);
  room.hitbox.setScale(SCALE);
  room.hitbox.set(
    DRONEROOM_X-2*SAFETY_DISTANCE,
    DRONEROOM_Y-2*SAFETY_DISTANCE,
    DRONEROOM_Z-2*SAFETY_DISTANCE
  );

  //landingarea.node.setParent(room.node);
  //landingarea.node.setOrientation(setVectorOrientationPlane(0,1,0));
  landingarea.node.setScale(SCALE);
  landingarea.node.setPosition(0,0,0);
  landingarea.node.move(landingarea.xPosition*SCALE,0,landingarea.zPosition*SCALE);

  landingarea.plane.setParent(landingarea.node);
  landingarea.plane.set(LANDINGAREA_X,LANDINGAREA_Z);
  landingarea.plane.setOrientation(setVectorOrientationPlane(0,1,0));

  landingarea.space.node.setParent(landingarea.node);
  landingarea.space.node.move(0,LANDINGAREA_HEIGHT,0);
  landingarea.space.set(LANDINGSPACE_X,LANDINGSPACE_Y,LANDINGSPACE_Z);

  ofNode tmpNode;
  tmpNode.setScale(SCALE);

  // QRs

  tmpNode.setOrientation(setVectorOrientation(-1,0,0));
  tmpNode.setPosition(6000,1800,2000);
  addQR("QR A", tmpNode, &node);

  tmpNode.setPosition(6000,1800,-2000);
  tmpNode.setOrientation(setVectorOrientation(-1,0,0));
  addQR("QR B", tmpNode, &node);

  tmpNode.setPosition(-6000,1800,2000);
  tmpNode.setOrientation(setVectorOrientation(1,0,0));
  addQR("QR C", tmpNode, &node);

  tmpNode.setPosition(-6000,1800,-2000);
  tmpNode.setOrientation(setVectorOrientation(1,0,0));
  addQR("QR D", tmpNode, &node);

  // Hoops

  ofNode tmpNodeHoop;
  tmpNodeHoop.setScale(SCALE);

  tmpNodeHoop.setPosition(-400,300,-400);
  tmpNodeHoop.setOrientation(setVectorOrientation(1,0,1));
  addHoop("Hoop A", tmpNodeHoop, &node);

  tmpNodeHoop.setPosition(400,250,400);
  tmpNodeHoop.setOrientation(setVectorOrientation(1,0,-1));
  addHoop("Hoop B",tmpNodeHoop, &node);

  tmpNodeHoop.setPosition(-400,200,400);
  tmpNodeHoop.setOrientation(setVectorOrientation(-1,0,1));
  addHoop("Hoop C",tmpNodeHoop, &node);

  tmpNodeHoop.setPosition(400,150,-400);
  tmpNodeHoop.setOrientation(setVectorOrientation(-1,0,-1));

  addHoop("Hoop D",tmpNodeHoop, &node);

}

int DroneRoom::addQR(string string, ofNode inputnode, ofNode *parent) {

  if(nQRs == maxQRs) return false;

  printf("Adding QR\n");

  ofVec3f orientation = inputnode.getUpDir();
  ofVec3f position = inputnode.getGlobalPosition();

  QRs[nQRs].node.setOrientation(setVectorOrientationPlane(orientation));
  QRs[nQRs].node.setPosition(position);
  QRs[nQRs].node.setParent(*parent);

  QRs[nQRs].number = nQRs+1;
  QRs[nQRs].zSize = A4WIDTH;
  QRs[nQRs].ySize = A4HEIGHT;

  QRs[nQRs].plane.setParent(QRs[nQRs].node);

  //QRs[nQRs].plane.setScale(QRs[nQRs].node.getScale());
  QRs[nQRs].plane.set(QRs[nQRs].zSize,QRs[nQRs].ySize);
  //QRs[nQRs].plane.setPosition(QRs[nQRs].node.getPosition());
  //QRs[nQRs].plane.setOrientation(setVectorOrientationPlane(vector));

  nQRs++;

  return nQRs;

}

int DroneRoom::addHoop(string string, ofNode inputnode, ofNode *parent) {

  printf("Adding hoop!\n");

  if(nHoops == maxHoops) return false;

  printf("Adding A!\n");

  Hoops[nHoops].string = string;
  Hoops[nHoops].number = nHoops+1;

  Hoops[nHoops].node.setScale(parent->getScale());

  Hoops[nHoops].hoop.setParent(Hoops[nHoops].node); // Hoop
  Hoops[nHoops].stand.setParent(Hoops[nHoops].node); // Stand
  Hoops[nHoops].hitbox.setParent(&Hoops[nHoops].node); // Hitbox
  Hoops[nHoops].passage.setParent(&Hoops[nHoops].node); // Passage

  Hoops[nHoops].hoop.set(HOOP_RADIUS,HOOP_THICKNESS,false);
  Hoops[nHoops].hitbox.set(HOOP_HITBOX_X,HOOP_HITBOX_Y,HOOP_HITBOX_Z);
  Hoops[nHoops].passage.set(HOOP_PASSAGE_X,HOOP_PASSAGE_Y,HOOP_PASSAGE_Z);

  updateHoop(nHoops+1,inputnode);

  nHoops++;

  return nHoops;

}

int DroneRoom::updateHoop(int n, ofNode inputnode) {

  // Orientation and Position

  ofVec3f orientation = inputnode.getUpDir();
  ofVec3f position = inputnode.getGlobalPosition();

  Hoops[n-1].node.setOrientation(setVectorOrientation(orientation));
  Hoops[n-1].node.setPosition(position);

  Hoops[n-1].stand.move(0,-HOOP_RADIUS-position.y,0);
  Hoops[n-1].stand.set(HOOP_THICKNESS/2,-HOOP_RADIUS-position.y,false);


  return true;

}

void DroneRoom::draw() {

  drawRoom();

  for(int i = 0; i < nHoops; i++) {
    drawHoop(&Hoops[i]);
  }

  for(int i = 0; i < nQRs; i++) {
    drawQR(&QRs[i]);
  }

  drawLandingArea();

}

void DroneRoom::drawRoom() {

  ofSetColor(room.nodeColor);
  room.node.draw();

  ofNoFill();
  ofSetColor(room.wireColor);
  room.box.drawWireframe();

}

void DroneRoom::drawHoop(Hoop *hoop) {

  ofSetColor(hoop->nodeColor);
  hoop->node.draw();
  ofSetColor(hoop->wireColor);
  hoop->hoop.drawWireframe();
  hoop->stand.drawWireframe();
  ofSetColor(hoop->hitboxColor);
  hoop->hitbox.draw();
  ofSetColor(hoop->passageColor);
  hoop->passage.draw();

  //drawQR(&hoop->qr);

}

void DroneRoom::drawQR(QR *qr) {

  ofSetColor(ofColor::purple);
  qr->node.draw();
  qr->plane.drawWireframe();

}

void DroneRoom::drawLandingArea() {

  ofSetColor(landingarea.nodeColor);
  landingarea.node.draw();
  ofSetColor(landingarea.wireColor);
  landingarea.plane.drawWireframe();
  ofSetColor(landingarea.spaceColor);
  landingarea.space.draw();
  landingarea.space.node.draw();

}

Wirebox DroneRoom::getRoomHitbox() {

  return room.hitbox;

}
