#include "ofMain.h"
#include "ofxNBxyz.h"

ofQuaternion setVectorOrientation(ofVec3f vector) {

  vector.normalize();

  //ofSetColor(ofColor::blue); // Origin (UP)
  ofVec3f originVector = ofVec3f(0,1,0);
  originVector.normalize();
  //ofDrawArrow(start,(start+originVector*400),10);


  /*
  ofSetColor(ofColor::red); // To X
  ofVec3f newVector = ofVec3f(1,0,0);
  newVector.normalize();
  ofDrawArrow(start,(start+newVector*400),10);
  */

  //ofSetColor(ofColor::green);
  ofVec3f rotationVector = originVector.getCrossed(vector);
  rotationVector.normalize();
  //ofDrawArrow(start,(start+rotationVector*400),10);

  float angle = originVector.angle(vector);

  /*

  ofQuaternion ofQtn = ofQuaternion(angle,rotationVector);

  ofBoxPrimitive boks;
  boks.set(20,200,20);
  boks.setPosition(0,0,0);
  boks.setOrientation(ofQtn);
  ofSetColor(ofColor::purple);
  ofFill();
  boks.draw();

  */

  return ofQuaternion(angle,rotationVector);

}

ofQuaternion setVectorOrientation(float x, float y, float z) {

  return setVectorOrientation(ofVec3f(x,y,z));

}

ofQuaternion setVectorOrientationPlane(ofVec3f vector) {

  vector.normalize();

  //ofSetColor(ofColor::blue); // Origin (UP)
  ofVec3f originVector = ofVec3f(0,0,1);
  originVector.normalize();
  //ofDrawArrow(start,(start+originVector*400),10);


  /*
  ofSetColor(ofColor::red); // To X
  ofVec3f newVector = ofVec3f(1,0,0);
  newVector.normalize();
  ofDrawArrow(start,(start+newVector*400),10);
  */

  //ofSetColor(ofColor::green);
  ofVec3f rotationVector = originVector.getCrossed(vector);
  rotationVector.normalize();
  //ofDrawArrow(start,(start+rotationVector*400),10);

  float angle = originVector.angle(vector);

  /*

  ofQuaternion ofQtn = ofQuaternion(angle,rotationVector);

  ofBoxPrimitive boks;
  boks.set(20,200,20);
  boks.setPosition(0,0,0);
  boks.setOrientation(ofQtn);
  ofSetColor(ofColor::purple);
  ofFill();
  boks.draw();

  */

  return ofQuaternion(angle,rotationVector);

}

ofQuaternion setVectorOrientationPlane(float x, float y, float z) {

  return setVectorOrientationPlane(ofVec3f(x,y,z));

}

Wirebox::Wirebox() {

  set(1,1,1);

  // Set parent

  for(int i = 0; i < corners; i++) {

    cornerNodes[i].setParent(node);

  }

  positionNode.setParent(node);

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

void Wirebox::setOrientation(ofQuaternion ofQ) {

  node.setOrientation(ofQ);

}

void Wirebox::setScale(float _scale) {

  ofVec3f vector;

  /*

  for(int i = 0; i < corners; i++) {

    vector.set(cornerNodes[i].getX(), cornerNodes[i].getY(), cornerNodes[i].getZ());

    cornerNodes[i].move(vector * (_scale / scale / 2));

  }

  */

  node.setScale(scale);

  for(int i = 0; i < corners; i++) {

    vector.set(cornerNodes[i].getX(), cornerNodes[i].getY(), cornerNodes[i].getZ());

    cornerNodes[i].move(vector);

  }

  scale = _scale;

}

void Wirebox::setParent(ofNode *_node) {

  node.setParent(*_node);

}

void Wirebox::set(float _X, float _Y, float _Z) {

  // Calculate new postions

  /*

  float newX = (_X - X) * scale / 2;
  float newY = (_Y - Y) * scale / 2;
  float newZ = (_Z - Z) * scale / 2;

  */

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

ofVec3f Wirebox::inside(ofVec3f position) {

  ofVec3f result;

  result.set(0,0,0);

  positionNode.setGlobalPosition(position);

  /*

      printf("Position X: %f\n", positionNode.getX());
      printf("Position Y: %f\n", positionNode.getY());
      printf("Position Z: %f\n", positionNode.getZ());

    */

    //centerNode.setPosition(node.getGlobalPosition());

    /*

      printf("Center X: %f\n", centerNode.getX());
      printf("Center Y: %f\n", centerNode.getY());
      printf("Center Z: %f\n", centerNode.getZ());



    //positionNode.setParent(node);
    //positionNode.setOrientation(setVectorOrientation(node.getUpDir()));

    printf("Drone X: %f\n", positionNode.getX());
    printf("Drone Y: %f\n", positionNode.getY());
    printf("Drone Z: %f\n", positionNode.getZ());

    */

  if(positionNode.getX() > X/2) {
    //printf("Outside Front.\n");
    result = result + ofVec3f(positionNode.getX() - X/2,0,0);

  } else if(positionNode.getX() < -X/2) {
    //printf("Outside Back.\n");
    result = result + ofVec3f(positionNode.getX() + X/2,0,0);

  }

  if(positionNode.getY() > Y/2) {
    //printf("Outside Top.\n");
    result = result + ofVec3f(0,positionNode.getY() - Y/2,0);

  } else if(positionNode.getY() < -Y/2) {
    //printf("Outside Bottom.\n");
    result = result + ofVec3f(0,positionNode.getY() + Y/2,0);

  }

  if(positionNode.getZ() > Z/2) {
    //printf("Outside Left.\n");
    result = result + ofVec3f(0,0,positionNode.getZ() - Z/2);

  } else if(positionNode.getZ() < -Z/2) {
    //printf("Outside Right.\n");
    result = result + ofVec3f(0,0,positionNode.getZ() + Z/2);

  }

  /*

    //printf("Function Return.\n");

    //result.set(0,0,0);

    //printf("Function Vector.\n");

    //("Scale: %f\n", node.getScale());

    printf("Length A: %f \n", result.length());

    printf("Scale: %f \n", scale);

    printf("Scale: %f \n", node.getScale());

    */

  result = result * scale;

  //printf("Length B: %f \n", result.length());

  if(result.length()) {ofDrawArrow(position, (position - result), 0);}

  return result;

}

ofVec3f Wirebox::outside(ofVec3f position) {

  ofVec3f result;

  float dist;

  result.set(0,0,0);

  positionNode.setGlobalPosition(position);

  /*

    printf("Testing Outside.\n");

    printf("Drone X: %f\n", positionNode.getX());
    printf("Drone Y: %f\n", positionNode.getY());
    printf("Drone Z: %f\n", positionNode.getZ());

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

    //printf("Inside.\n");

    dist = X/2 - positionNode.getX();
    result.set(dist,0,0);

    if(dist > X/2 + positionNode.getX()) {
      //printf("Dist: %f\n",dist);
      dist = X/2 + positionNode.getX();
      //printf("Dist: %f\n",dist);
      result.set(-dist,0,0);
    }

    if(dist > Y/2 - positionNode.getY()) {
      dist = (Y/2 - positionNode.getY());
      result.set(0,dist,0);
    }

    if(dist > Y/2 + positionNode.getY()) {
      dist = -(Y/2 + positionNode.getY());
      result.set(0,dist,0);
    }

    if(dist > Z/2 - positionNode.getZ()) {
      dist = (Z/2 - positionNode.getZ());
      result.set(0,0,dist);
    }

    if(dist > Z/2 + positionNode.getZ()) {
      dist = -(Z/2 + positionNode.getZ());
      result.set(0,0,dist);
    }

  } else return result;

  result = result * scale;

  if(result.length()) {ofDrawArrow(position, (position + result), 0);}

  return result;


}
