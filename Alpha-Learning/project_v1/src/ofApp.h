#pragma once

#include "ofMain.h"
#include "DroneControl.h"
#include "ComputerVision.h"
#include "UserInterface.h"
#include "Drone.h"
#include "DroneRoom.h"
#include "DroneAI.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

	private:

		int keys[264];

		// Drone
		Drone drone;
		DroneRoom droneroom;
		DroneControl dronecontrol;
		DroneAI droneAI;

		ofEasyCam camera;
		ofLight light;

};
