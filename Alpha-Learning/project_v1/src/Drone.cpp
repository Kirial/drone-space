#include "ofMain.h"
#include "settings.h"
#include "Drone.h"

Drone::Drone() {
  x = originX = 0;
  y = originY = 0;
  z = originZ = 0;

  node.setScale(SCALE);

  hitbox.setParent(node);
  hitbox.set(DRONE_HITBOX_L, DRONE_HITBOX_H, DRONE_HITBOX_W);

}

void Drone::moveToLandingArea(ofNode landingArea) {


}

void Drone::draw() {

  drawHitbox();

}

void Drone::drawHitbox() {

  ofNoFill();
  ofSetColor(0,255,0);
  hitbox.drawWireframe();

}

int Drone::upDown(float distance) {
  ofVec3f yAxis = node.getYAxis() * distance;
  node.move(yAxis);
  return true;
}

int Drone::forwardBackward(float distance) {
  ofVec3f xAxis = node.getXAxis() * distance;
  node.move(xAxis);
  return true;
}

int Drone::strafeLeftRight(float distance) {
  ofVec3f zAxis = node.getZAxis() * distance;
  node.move(zAxis);
  return true;

}

int Drone::turnLeftRight(float angle) {
  node.rotate(angle,0,1,0);
}

ofVec3f Drone::getPosition() {

  return node.getPosition();

}

/*

int Drone::move(float _x, float _y, float _z) {
  x += _x;
  y += _y;
  z += _z;
  return true;
}

int Drone::set(float _x, float _y, float _z) {
  x = _x;
  y = _y;
  z = _z;
  return true;
}

int Drone::yaw(float y) {yawOffset += y; return true;}
int Drone::setYaw(float y) {yawOffset = y; return true;}
int Drone::roll(float r) {rollOffset += r; return true;}
int Drone::setRoll(float r) {rollOffset = r; return true;}
int Drone::pitch(float p) {pitchOffset +=p; return true;}
int Drone::setPitch(float p) {pitchOffset =p; return true;}

*/
