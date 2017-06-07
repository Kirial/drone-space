#include "ofApp.h"
#include "settings.h"
#include "ofxNBxyz.h"

//--------------------------------------------------------------
void ofApp::setup(){

  //ofSetVerticalSync(true);
  ofBackground(255);

  /*
  ofSetSmoothLighting(true);
  pointLight.setDiffuseColor(ofFloatColor(.85, .85, .55));
  pointLight.setSpecularColor(ofFloatColor(1.f, 1.f, 1.f));
  */

  ofEnableLighting();
  light.enable();

  camera.setDistance(1000);

  // Drone Constructors
  dronecontrol.setup(&drone);
  droneAI.setup(&drone, &droneroom, &dronecontrol);

  //ofSetSphereResolution(24);


}

//--------------------------------------------------------------
void ofApp::update(){

  dronecontrol.command(&drone);

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
    droneAI.drawAntiCollision();


    /*

    Wirebox wirebox;
    wirebox.set(200,200,200);
    wirebox.draw();
    wirebox.setScale(2);
    wirebox.draw();
    wirebox.setOrientation(setVectorOrientation(1,1,1));
    wirebox.setScale(1);
    wirebox.set(400,400,400);
    wirebox.draw();
    //wirebox.draw();

    */

  camera.end();

  ofDisableDepthTest();

  // Draw 2D Graphical UI


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

  //printf("%i\n", key);

  if(!keys[key]) {
    dronecontrol.keyboard(key, true);
    keys[key] = true;
  }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

  if(keys[key]) {
    dronecontrol.keyboard(key, false);
    keys[key] = false;
  }

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
