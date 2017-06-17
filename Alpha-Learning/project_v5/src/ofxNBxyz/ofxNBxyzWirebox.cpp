#include "ofMain.h"
#include "ofxNBxyzWirebox.h"

Wirebox::Wirebox() {

  set(1,1,1);

  // Set parent
  for(int i = 0; i < corners; i++) {

    cornerNodes[i].setParent(node);

  }

}

void Wirebox::drawNodes() {

  // Nodes
  node.draw();
  for(int i = 0; i < corners; i++) {
    cornerNodes[i].draw();
  }

}

void Wirebox::draw() {

  for(int i = 0; i < 4; i++) {

    // Top
    ofDrawArrow(cornerNodes[i].getGlobalPosition(), cornerNodes[(i+1)%4].getGlobalPosition(), 0);

    // Center
    ofDrawArrow(cornerNodes[i].getGlobalPosition(), cornerNodes[4+i].getGlobalPosition(), 0);

    // Bottom
    ofDrawArrow(cornerNodes[i+4].getGlobalPosition(), cornerNodes[(i+5)%4+4].getGlobalPosition(), 0);

  }


}

void Wirebox::set(float _X, float _Y, float _Z) {

  float newX = (_X - X) / 2;
  float newY = (_Y - Y) / 2;
  float newZ = (_Z - Z) / 2;

  ofVec3f vector;

  // Top Front Left
  vector.set(newX,newY,-newZ);
  cornerNodes[0].move(vector);

  // Top Front Right
  vector.set(newX,newY,newZ);
  cornerNodes[1].move(vector);

  // Top Rear Left
  vector.set(-newX,newY,newZ);
  cornerNodes[2].move(vector);

  // Top Rear Right
  vector.set(-newX,newY,-newZ);
  cornerNodes[3].move(vector);

  // Bottom Front Left
  vector.set(newX,-newY,-newZ);
  cornerNodes[4].move(vector);

  // Bottom Front Right
  vector.set(newX,-newY,newZ);
  cornerNodes[5].move(vector);

  // Bottom Rear Left
  vector.set(-newX,-newY,newZ);
  cornerNodes[6].move(vector);

  // Bottom Rear Right
  vector.set(-newX,-newY,-newZ);
  cornerNodes[7].move(vector);

  // Save new positions

  X = _X;
  Y = _Y;
  Z = _Z;

}

float Wirebox::inside(ofVec3f position, ofVec3f *result) {

  ofVec3f tmpResult;

  tmpResult.set(0,0,0);


  positionNode.setGlobalPosition(position);

  /*

      printf("X: %f\n", X);
      printf("Y: %f\n", Y);
      printf("Z: %f\n", Z);

    //centerNode.setPosition(node.getGlobalPosition());

      printf("Center X: %f\n", node.getX());
      printf("Center Y: %f\n", node.getY());
      printf("Center Z: %f\n", node.getZ());



    //positionNode.setParent(node);
    //positionNode.setOrientation(setVectorOrientation(node.getUpDir()));

    printf("Drone X: %f\n", positionNode.getX());
    printf("Drone Y: %f\n", positionNode.getY());
    printf("Drone Z: %f\n", positionNode.getZ());

    */

  if(positionNode.getX() > X/2) {
    //printf("Outside North.\n");
    tmpResult = tmpResult + ofVec3f(positionNode.getX() - X/2,0,0);

  } else if(positionNode.getX() < -X/2) {
    //printf("Outside South.\n");
    tmpResult = tmpResult + ofVec3f(positionNode.getX() + X/2,0,0);

  }

  if(positionNode.getY() > Y) {
    //printf("Y: %f. Drone is: %f.\n", Y/2, positionNode.getY());
    //printf("Outside Top.\n");
    tmpResult = tmpResult + ofVec3f(0,positionNode.getY() - Y/2,0);

  } else if(positionNode.getY() < 0) {
    //printf("Outside Bottom.\n");
    tmpResult = tmpResult + ofVec3f(0,positionNode.getY() + Y/2,0);

  }

  if(positionNode.getZ() > Z/2) {
    //printf("Outside West.\n");
    tmpResult = tmpResult + ofVec3f(0,0,positionNode.getZ() - Z/2);

  } else if(positionNode.getZ() < -Z/2) {
    //printf("Outside East.\n");
    tmpResult = tmpResult + ofVec3f(0,0,positionNode.getZ() + Z/2);

  }

  //printf("Length B: %f \n", result.length());

  if(tmpResult.length()) {

    //ofDrawArrow(position, (position - tmpResult), 0);

    //*result = position - tmpResult;

    *result = tmpResult;

    printf("Inside dist: %f.\n", tmpResult.length());

    return tmpResult.length();
  }

  return 0;

}

float Wirebox::outside(ofVec3f position, ofVec3f *result) {

  ofVec3f tmpResult;

  float dist;

  tmpResult.set(0,0,0);

  positionNode.setGlobalPosition(position);

  /*

  printf("Testing Outside.\n");

  printf("Drone X: %f\n", positionNode.getX());
  printf("Drone Y: %f\n", positionNode.getY());
  printf("Drone Z: %f\n", positionNode.getZ());

  printf("X: %f\n", X/2);
  printf("Y: %f\n", Y/2);
  printf("Z: %f\n", Z/2);

  printf("X: %f\n", X/2);
  printf("Y: %f\n", Y/2);
  printf("Z: %f\n", Z/2);

  */

  if(
    positionNode.getX() < X/2 &&
    positionNode.getX() > -X/2 &&
    positionNode.getY() < Y/2 &&
    positionNode.getY() > -Y/2 &&
    positionNode.getZ() < Z/2 &&
    positionNode.getZ() > -Z/2
  ) {

    printf("Inside.\n");

    dist = X/2 - positionNode.getX();
    tmpResult.set(dist,0,0);

    if(dist > X/2 + positionNode.getX()) {
      //printf("Dist: %f\n",dist);
      dist = X/2 + positionNode.getX();
      //printf("Dist: %f\n",dist);
      tmpResult.set(-dist,0,0);
    }

    if(dist > Y/2 - positionNode.getY()) {
      dist = (Y/2 - positionNode.getY());
      tmpResult.set(0,dist,0);
    }

    if(dist > Y/2 + positionNode.getY()) {
      dist = -(Y/2 + positionNode.getY());
      tmpResult.set(0,dist,0);
    }

    if(dist > Z/2 - positionNode.getZ()) {
      dist = (Z/2 - positionNode.getZ());
      tmpResult.set(0,0,dist);
    }

    if(dist > Z/2 + positionNode.getZ()) {
      dist = -(Z/2 + positionNode.getZ());
      tmpResult.set(0,0,dist);
    }

  }

  if(tmpResult.length()) {

    //ofSetColor(255,0,0);

    //ofDrawArrow(ofVec3f(0,0,0),tmpResult, 0);

    //*result = position - tmpResult;

    *result = tmpResult;

    //printf("Outside dist: %f.\n", tmpResult.length());

    return tmpResult.length();

  }

  return 0;

}
