#include "ofMain.h"
#include "settings.h"
#include "Drone.h"
#include "DroneRoom.h"
#include "DroneControl.h"
#include "DroneAI.h"
#include "ofxNBxyz.h"

DroneAI::DroneAI() {

}

void DroneAI::setup(Drone *_drone, DroneRoom *_droneroom, DroneControl *_dronecontrol) {

  drone = _drone;
  droneroom = _droneroom;
  dronecontrol = _dronecontrol;

}

void DroneAI::drawAntiCollision() {

  // Room Hitbox
  ofSetColor(ofColor::red);
  droneroom->getRoomHitbox().draw();

  droneroom->getRoomHitbox().inside(drone->getPosition());
  droneroom->getRoomHitbox().outside(drone->getPosition());

}
