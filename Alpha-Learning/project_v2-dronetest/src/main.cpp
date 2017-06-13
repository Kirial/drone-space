#include "ofMain.h"
#include "ofApp.h"
#include "/Users/nb/Developer/cvdrone-master/src/ardrone/ardrone.h"



//========================================================================
int main( ){

	ARDrone ardrone;

	/*

	// Initialize
	if (!ardrone.open()) {
			std::cout << "Failed to initialize." << std::endl;
			return -1;
	}

	*/

	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
