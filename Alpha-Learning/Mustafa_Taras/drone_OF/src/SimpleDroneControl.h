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
		void takeOff();

		int droneFly(float z, float y, float x, float spin);
		void setZero();

		void emergency();
	
private :ofxARDrone::Drone drone;
};

#endif SimpleDroneControl_H