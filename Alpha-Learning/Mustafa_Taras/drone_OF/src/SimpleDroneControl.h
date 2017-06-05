#pragma once
#include "ofxARDrone.h"
#include "ofxARDroneOscBridge.h"

#ifndef SimpleDroneControl_H
#define SimpleDroneControl_H


using namespace std;
class SimpleDroneControl{

public:

		SimpleDroneControl();
		~SimpleDroneControl();
		bool isConnected();
		void land();
		int up(int dist); // Space
		int down(int dist); // Shift

		// XY Basic Control
		int forward(); // w W
		int backward(); // s S

		int strafeLeft(); // A a
		int strafeRight(); // D d

		int turnLeft(); // E e
		int turnRight(); // Q q

		// XY Advanced Control
		int forwardStrafeLeft(); // WA wa
		int forwardStrafeRight(); // WD wd

		int backwardStrafeLeft(); // SA sa
		int backwardStrafeRight(); // SD sd

		int turnLeftForward(); // WQ wq
		int turnRightForward(); // WE we

		int leftSidewaysBackward(); // SQ sq
		int rightSidewaysBackward(); // SE se

		int strafeLeftTurnLeft(); // QA qa
		int strafeLeftTurnRight(); // QD qd

		int strafeRightTurnLeft(); // EA ea
		int strafeRightTurnRight(); // ED ed

	
private :ofxARDrone::Drone drone;
};

#endif SimpleDroneControl_H