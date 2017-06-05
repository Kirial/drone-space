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

	switch (key) {
	case 'w': 
		start_z = start_z + 0.05;
		break;
	case 's':
		start_z = start_z + 0.05;
		break;
	case 'a':
		start_sp = start_sp + 0.05;
		break;
	case 'd':
		start_sp = start_sp - 0.05;
		break;
	case 'i':
		start_x = start_x + 0.05;
		break;
	case 'k':
		start_x = start_x - 0.05;
		break;
	case 'l':
		start_y = start_y + 0.05;
		break;
	case 'j':
		start_y = start_y - 0.05;
		break;
	case 'z':
		test.setZero();
		break;
	case 't':
		test.takeOff();
		break;
	case 'y':
		test.land();
		break;
	case 'e':
		test.emergency();
		break;
	default:
		cout << key << endl;
		break;
	}
	test.droneFly(start_z,start_y, start_x,start_sp);
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
