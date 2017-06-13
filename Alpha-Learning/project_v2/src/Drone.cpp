#include "ofMain.h"
#include "settings.h"
#include "Drone.h"

Drone::Drone() {

  box.setParent(node);
  node.setPosition(DRONE_START_X,DRONE_START_Y, DRONE_START_Z);

}

ofVec3f Drone::getPosition() {

  return node.getGlobalPosition();

}
