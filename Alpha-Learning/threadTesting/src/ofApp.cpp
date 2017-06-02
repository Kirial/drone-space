#include "ofApp.h"
#include <iostream>

//--------------------------------------------------------------
void ofApp::setup(){

  cout << "Hello, World 1.";

  control = Control(cli);

  control.startThread(true);
  vision.startThread(true);
  autopilot.startThread(true);
  cli.startThread(true);

}

//--------------------------------------------------------------
void ofApp::update(){

  cout << "Update.\n\r";



}

//--------------------------------------------------------------
void ofApp::draw(){

  cout << "Draw.\n\r";

}

void ofApp::exit() {

  control.stopThread();
  vision.stopThread();
  autopilot.stopThread();
  cli.stopThread();

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
