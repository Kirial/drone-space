#include "ofApp.h"
#include "settings.h"

//--------------------------------------------------------------
void ofApp::setup(){

  //ofSetVerticalSync(true);
  ofBackground(255);

  ofEnableLighting();
  light.enable();

  camera.setDistance(1000);

  ofResetElapsedTimeCounter();

}

//--------------------------------------------------------------
void ofApp::update(){

  drone.update();

  droneai.update();

}

//--------------------------------------------------------------
void ofApp::draw(){

  ofEnableDepthTest();

  //pointLight.enable();
  light.setPosition(1000,1000,1000);

  camera.begin();

  // Draw 3D

  droneroom.draw();

  drone.draw();

  droneai.draw();

  camera.end();

  ofDisableDepthTest();

  // Draw 2D Graphical UI

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

  keys[key] = true;

  userinterface.keyboard(key, keys[key]);

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

  keys[key] = false;

  userinterface.keyboard(key, keys[key]);

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
