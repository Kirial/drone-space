#include "ofApp.h"
#include <iostream>
#include "control.h"

//--------------------------------------------------------------
void ofApp::setup(){

  cout << "Hello, World 1.";

  controlThread.startThread(true, false);
  visionThread.startThread(true, false);

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

  controlThread.stopThread();
  visionThread.stopThread();

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
