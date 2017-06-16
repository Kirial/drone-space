#include "ofMain.h"
#include "settings.h"
#include "Drone.h"

Drone::Drone() {

  box.setParent(node);
  forward.setParent(node);
  direction.setParent(node);

  forward.move(DRONE_ORIENTATION_VECTOR,0,0);
  box.set(DRONE_BOX_X, DRONE_BOX_Y, DRONE_BOX_Z);
  node.setPosition(DRONE_START_X,DRONE_START_Y, DRONE_START_Z);

  // Setup View Drawings

  viewOffsetX = (DRONE_VIEW_W/2/DRONE_VIEW_PIXELCM)/(tan(ofDegToRad(DRONE_VIEW_ANGLE/2)));
  viewOffsetY = DRONE_VIEW_H/2/DRONE_VIEW_PIXELCM;
  viewOffsetZ = DRONE_VIEW_W/2/DRONE_VIEW_PIXELCM;

  view[0].setPosition(viewOffsetX,viewOffsetY,-viewOffsetZ);
  view[1].setPosition(viewOffsetX,viewOffsetY,viewOffsetZ);
  view[2].setPosition(viewOffsetX,-viewOffsetY,viewOffsetZ);
  view[3].setPosition(viewOffsetX,-viewOffsetY,-viewOffsetZ);

  // Hoop

  for(int i = 0; i < HOOP_COUNT; i++) {

    viewedHoops[i].set(0,1,false);
    viewedHoops[i].rotate(90,1,0,0);
    viewedHoops[i].rotate(90,0,1,0);
    viewedHoops[i].setParent(node);
    viewedHoops[i].move(viewOffsetX, viewOffsetY, -viewOffsetZ);

    projectedHoops[i].set(0,1,false);
    projectedHoops[i].rotate(90,1,0,0);
    projectedHoops[i].rotate(90,0,1,0);
    projectedHoops[i].setParent(node);

    viewedHoopsNumber[i] = false;

  }

  // QR

  for(int i = 0; i < (HOOP_COUNT+QR_COUNT); i++) {

    viewedQRs[i].set(0,0);
    viewedQRs[i].rotate(90,1,0,0);
    viewedQRs[i].rotate(90,0,0,1);
    viewedQRs[i].setParent(node);
    viewedQRs[i].move(viewOffsetX, viewOffsetY, -viewOffsetZ);

    projectedQRs[i].set(0,0);
    projectedQRs[i].rotate(90,1,0,0);
    projectedQRs[i].rotate(90,0,0,1);
    projectedQRs[i].setParent(node);

    viewedQRsNumber[i] = false;

  }

  // Test Drawings

  addHoop(40,40,100,7);
  addHoop(60,60,100,8);
  addHoop(100,100,100,9);

  addQR(400,400,100,7);
  addQR(500,500,100,8);
  addQR(600,600,100,9);

  // Set Flight- and DroneMode

  setFlightMode(NOTFLYING);
  setDroneMode(LANDED);

  for(int i = 0; i < 4; i++) {
    view[i].setParent(node);
  }

}

// Update, Draw
void Drone::draw() {

  // The Drone
  ofSetColor(255,0,255);
  box.drawWireframe();

  // Draw Forward Direction
  ofDrawArrow(node.getGlobalPosition(), forward.getGlobalPosition(), 10);

  // Draw Destination Vector
  ofDrawArrow(node.getGlobalPosition(), destination, 0);

  // Draw Destination Offset Vector
  ofSetColor(0,0,255);
  ofDrawArrow(node.getGlobalPosition(), node.getGlobalPosition() + destinationOffset, 20);

  // Draw Direction Vector
  ofSetColor(255,255,0);
  ofDrawArrow(node.getGlobalPosition(), direction.getGlobalPosition(), 20);

  drawView();

}
void Drone::drawView() {

  ofSetColor(ofColor::cyan);

  for(int i = 0; i < 4; i++) {

    ofDrawArrow(node.getGlobalPosition(),view[i].getGlobalPosition());

    ofDrawArrow(view[i].getGlobalPosition(),view[(i+1)%4].getGlobalPosition());

  }

  drawViewedHoops();
  drawViewedQRs();

}

void Drone::addHoop(int x, int y, int h, int n) {

  //printf("Adding hoop - x: %i, y: %i, h: %i, n: %i.\n", x, y, h, n);

  viewedHoops[seenHoopsCount].move(0,-x/DRONE_VIEW_PIXELCM,y/DRONE_VIEW_PIXELCM);
  viewedHoops[seenHoopsCount].set(h/DRONE_VIEW_PIXELCM,1,false);
  viewedHoopsNumber[seenHoopsCount] = n;

  seenHoopsCount++;

}

void Drone::resetHoops() {

  seenHoopsCount = 0;

}

void Drone::addQR(int x, int y, int h, int n) {

  //printf("Adding QR - x: %i, y: %i, h: %i, n: %i.\n", x, y, h, n);

  viewedQRs[seenQRsCount].move(0,-x/DRONE_VIEW_PIXELCM,y/DRONE_VIEW_PIXELCM);
  viewedQRs[seenQRsCount].set(h/DRONE_VIEW_PIXELCM,h/DRONE_VIEW_PIXELCM);
  viewedQRsNumber[seenQRsCount] = n;

  seenQRsCount++;

}

void Drone::resetQRs() {

  seenQRsCount = 0;

}

void Drone::drawViewedHoops() {

  for(int i = 0; i < seenHoopsCount; i++) {

    ofSetColor(0,255,255); // Cyan
    viewedHoops[i].draw();

  }

}

void Drone::drawProjectedHoops() {

  for(int i = 0; i < seenHoopsCount; i++) {


  }

}

void Drone::drawViewedQRs() {

  for(int i = 0; i < seenQRsCount; i++) {

    ofSetColor(0,255,255); // Cyan
    viewedQRs[i].draw();

  }

}

void Drone::drawProjectedQRs() {


}

void Drone::update() {

  // Destination offset

  destinationOffset = destination - node.getGlobalPosition();

  direction.setGlobalPosition(destination);

  // Rotation angle offset

  angleOffset = (direction.getPosition() * ofVec3f(1,0,1)).angle(forward.getPosition());

  angleRotationDirection = (direction.getPosition() * ofVec3f(1,0,1)).getCrossed(forward.getPosition());

  if(angleRotationDirection.y > 0) angleOffset = -angleOffset;

  //printf("Angle Offset: %f.\n", angleOffset);

}
void Drone::instruction() {

  if(abs(angleOffset) > DRONE_ANGLE_OFFSET && dronemode != TAKEOFF && dronemode != LANDING) {

    ofVec3f angleRotationDirection = (direction.getPosition() * ofVec3f(1,0,1)).getCrossed(forward.getPosition());

    float angleRotation = DRONE_ROTATION_SPEED;

    if(angleRotation > abs(angleOffset)) angleRotation = abs(angleOffset);

    if(angleRotationDirection.y < 0) {

      //printf("Turn Left.\n");

      node.rotate(angleRotation,0,1,0);

    }

    else {

      //printf("Turn Right.\n");

      node.rotate(-angleRotation,0,1,0);

    }

  }

  if(destinationOffset.length()) {

    //printf("Moving drone.\n");

    float moveDistance = destinationOffset.length();

    //printf("Destination offset: %f.\n",moveDistance);

    if(destinationOffset.length() < speed) moveDistance = destinationOffset.length();

    else moveDistance = speed;

    node.move(moveDistance * destinationOffset.getNormalized());

  }

}

// Godlike
ofVec3f Drone::getPosition() {

  return node.getGlobalPosition();

}
ofVec3f Drone::setPosition(ofVec3f position) {

  ofVec3f difference = position - node.getGlobalPosition();

  node.setGlobalPosition(position);

  return difference;

}

// Autonomous
ofVec3f Drone::getDestination() {
 return destination;
}
ofVec3f Drone::setDestination(ofVec3f _destination) {

  ofVec3f result = _destination - destination;

  direction.setGlobalPosition(_destination);

  destination = _destination;

  return result;

}
ofVec3f Drone::getDirection() {
  return direction.getPosition();
}
ofVec3f Drone::getDestinationOffset() {
  return destinationOffset;
}
float Drone::getDestinationDistance() {

  //printf("Distance: %f.\n", destinationOffset.length());

  return destinationOffset.length();
}
float Drone::getAngleOffset() {

  return angleOffset;

}

// Flightmode and Speed
void Drone::setFlightMode(FlightMode _flightmode) {
  flightmode = _flightmode;

  switch(flightmode) {
    case NOTFLYING:
      speed = 0;
      break;
    case STEADY:
      speed = DRONE_STEADY_SPEED;
      break;
    case NORMAL:
      speed = DRONE_NORMAL_SPEED;
      break;
    case FAST:
      speed = DRONE_FAST_SPEED;
      break;
    case INSANE:
      speed = DRONE_INSANE_SPEED;
      break;
    case LUDICROUS:
      speed = DRONE_LUDICROUS_SPEED;
      break;
    default:
      speed = DRONE_NORMAL_SPEED;
      break;
  }
}
FlightMode Drone::getFlightMode() {
  return flightmode;
}
int Drone::getSpeed() {
  return speed;
}

// Drone Mode
void Drone::setDroneMode(DroneMode _dronemode) {
  dronemode = _dronemode;
}
DroneMode Drone::getDroneMode() {
  return dronemode;
}
void printFlightMode(FlightMode flightmode) {

  switch(flightmode) {
    case NOTFLYING:
      printf("NOTFLYING\n");
      break;
    case STEADY:
      printf("STEADY\n");
      break;
    case NORMAL:
      printf("NORMAL\n");
      break;
    case FAST:
      printf("FAST\n");
      break;
    case INSANE:
      printf("INSANE\n");
      break;
    case LUDICROUS:
      printf("LUDICROUS\n");
      break;
    default:
    break;

  }

}
void printDroneMode(DroneMode dronemode) {

  switch(dronemode) {
    case READY:
      printf("READY\n");
      break;
    case HOLD:
      printf("HOLD\n");
      break;
    case AUTONOMOUS:
      printf("AUTONOMOUS\n");
      break;
    case MANUAL:
      printf("MANUAL\n");
      break;
    case LANDED:
      printf("LANDED\n");
      break;
    case TAKEOFF:
      printf("TAKEOFF\n");
      break;
    case LANDING:
      printf("LANDING\n");
      break;
    default:
    break;

  }

}
