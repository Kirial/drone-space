#include "ofxARDrone.h"
#include "ofxARDroneOscBridge.h"
#include "SimpleDroneControl.h"

SimpleDroneControl::SimpleDroneControl() {
	string msg;
	ofLogVerbose("ofxARDrone::SimpleDroneControl");
	drone.connect();
	Sleep(5000);
	int try_count = 0;
	

	while (!(drone.state.isConnected())) {
		try_count++;
		drone.connect();
		setZero();
		Sleep(500);
		if (try_count > 1000) {
			ofLogVerbose("could not connect");
			return;
		}
	}
	ofLogVerbose("connected");
}

SimpleDroneControl::~SimpleDroneControl() {
	drone.disconnect();
}

bool SimpleDroneControl::isConnected() {
	return drone.state.isConnected(); 
}

void SimpleDroneControl::setZero() {
	drone.controller.spinSpeed = 0;
	drone.controller.rollAmount = 0;
	drone.controller.pitchAmount = 0;
	drone.controller.spinSpeed = 0;
	drone.update();
}

void SimpleDroneControl::takeOff() {
	drone.controller.takeOff(!drone.state.isTakingOff(), 3000);
	drone.update();
}
void SimpleDroneControl::land() {
	drone.controller.land(!drone.state.isTakingOff(),3000);
	drone.update();
}

int SimpleDroneControl::droneFly(float z, float y, float x, float spin) {
	drone.controller.spinSpeed = z;
	drone.controller.rollAmount = y;
	drone.controller.pitchAmount = x;
	drone.controller.spinSpeed = spin;
	drone.update();
	return 1;
}

void SimpleDroneControl::emergency() {
	drone.controller.emergency(1);
}