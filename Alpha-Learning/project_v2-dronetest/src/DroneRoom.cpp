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

  // Hoop
  hoop.rotate(90,0,0,1);
  hoop.set(HOOP_RADIUS, HOOP_THICKNESS,false);
  hoop.setParent(node);

  // Stand
  //stand.setParent(node);

  // Hitbox
  hitbox.set(HOOP_HITBOX_X, HOOP_HITBOX_Y, HOOP_HITBOX_Z);
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

void Hoop::setPosition(float x, float y, float z) {

  node.setPosition(x,y,z);
  stand.setPosition(x,(y-HOOP_RADIUS)/2,z);
  stand.set(HOOP_THICKNESS,y-HOOP_RADIUS);

}

LandingPlatform::LandingPlatform() {

  // Plane
  platform.rotate(90,1,0,0);
  platform.set(LANDINGPLATFORM_X, LANDINGPLATFORM_Z);
  platform.setParent(node);

  // Wirebox
  point.node.move(0,LANDINGPLATFORM_POS_Y,0);
  point.node.setParent(node);

}

void LandingPlatform::draw() {

  node.draw();
  platform.draw();
  point.draw();

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

  hoops[0].setPosition(200,200,200);
  hoops[1].setPosition(-200,300,-200);

  hoops[0].node.setParent(node);
  hoops[1].node.setParent(node);

  hoopCount = 2;

  // QR

  QRs[0].setPosition(600,200,200);
  QRs[1].setPosition(-600,200,-200);

  QRs[0].node.setParent(node);
  QRs[1].node.setParent(node);

  qrCount = 2;

}

void DroneRoom::draw() {

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
