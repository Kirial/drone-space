#include "ofApp.h"
#include "settings.h"

//--------------------------------------------------------------
void ofApp::setup(){

  //ofSetVerticalSync(true);
  ofBackground(255);

  ofEnableLighting();
  light.enable();

  camera.setDistance(1000);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

  ofEnableDepthTest();

  //pointLight.enable();
  light.setPosition(1000,1000,1000);

  camera.begin();

  // Draw 3D

  droneroom.draw();

  droneai.draw();

  camera.end();

  ofDisableDepthTest();

  // Draw 2D Graphical UI

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
