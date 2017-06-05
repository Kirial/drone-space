#include "ofApp.h"
#include "ofxARDrone.h"
#include "SimpleDroneControl.h"
//--------------------------------------------------------------
void ofApp::setup(){
	cout << "Hello World" << endl;
	ofSetLogLevel(OF_LOG_VERBOSE);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	int start = 0; 
	switch (key) {
	case 'w': 
		start=start+0.02;
		test.up(start);
		break;
	case 's':
		start = start - 0.02;
		test.down(start);
		break;
	case 'p':
		test.land();
		break;
	default:
		cout << key << endl;
		break;
	}
	
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
