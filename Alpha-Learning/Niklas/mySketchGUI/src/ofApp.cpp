#include "ofApp.h"
#include "gui.h"

int exitApp();

//--------------------------------------------------------------
void ofApp::setup(){

  ofTrueTypeFont::setGlobalDpi(72);

  minecraft14.load("Minecraftia.ttf", 14, true, true);
  minecraft14.setLineHeight(16);
  minecraft14.setLetterSpacing(1);

  btnExit.set(20,20,ofGetWindowWidth()-30,10,ofColor::purple,ofColor::black,"X",&minecraft14);
  btnExit.setHoverAppearance(ofColor::black, ofColor::white);
  btnExit.setFunction(HoverFunction,exitApp);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

  ofBackground(ofColor::white);

  ofSetColor(ofColor::black);

  ofFill();

  ofDrawRectangle(10,10,100,100);

  minecraft14.drawString("Font Example - use keyboard to type", 30, 35);

  btnExit.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

  btnExit.hover(x,y);

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

int exitApp() {

  printf("Exitting App.\n");

  ofExit(0);

}
