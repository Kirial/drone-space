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
		drone.update();
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

void SimpleDroneControl::land() {
	drone.controller.land(true,5000);
	drone.update();
}

int SimpleDroneControl::up(int dist) {
	drone.controller.takeOff(!drone.state.isTakingOff(), 3000);
	drone.controller.pitchAmount -= dist;
	drone.update();
	return 1;
} // Space
	int SimpleDroneControl::down(int dist) {
		drone.controller.pitchAmount += dist;
		drone.update();
		return 1;
	} // Shift

				// XY Basic Control
	int SimpleDroneControl::forward() {
		return -1;
	} // w W
	int SimpleDroneControl::backward() {
		return -1;
	} // s S

	int SimpleDroneControl::strafeLeft() {
		return -1;
	} // A a
	int SimpleDroneControl::strafeRight() {
		return -1;
	} // D d

	int SimpleDroneControl::turnLeft() {
		return -1;
	} // E e
	int SimpleDroneControl::turnRight() {
		return -1;
	} // Q q

					 // XY Advanced Control
	int SimpleDroneControl::forwardStrafeLeft() {
		return -1;
	} // WA wa
	int SimpleDroneControl::forwardStrafeRight() {
		return -1;
	} // WD wd

	int SimpleDroneControl::backwardStrafeLeft() {
		return -1;
	} // SA sa
	int SimpleDroneControl::backwardStrafeRight() {
		return -1;
	} // SD sd

	int SimpleDroneControl::turnLeftForward() {
		return -1;
	} // WQ wq
	int SimpleDroneControl::turnRightForward() {
		return -1;
	} // WE we

	int SimpleDroneControl::leftSidewaysBackward() {
		return -1;
	} // SQ sq
	int SimpleDroneControl::rightSidewaysBackward() {
		return -1;
	} // SE se

	int SimpleDroneControl::strafeLeftTurnLeft() {
		return -1;
	} // QA qa
	int SimpleDroneControl::strafeLeftTurnRight() {
		return -1;
	} // QD qd

	int SimpleDroneControl::strafeRightTurnLeft() {
		return -1;
	} // EA ea
	int SimpleDroneControl::strafeRightTurnRight() {
		return -1;
	} // ED ed
