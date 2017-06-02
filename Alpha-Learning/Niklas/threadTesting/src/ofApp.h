#pragma once

#include "ofMain.h"
//#include "control.h"
#include "vision.h"
#include "control.h"
#include "autopilot.h"
#include "cli.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void exit();

		// Niklas

		int threadSwitch();

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

		Control control;
		Vision vision;
		Autopilot autopilot;
		Cli cli;



};
