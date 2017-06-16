#include "ofMain.h"
#include "settings.h"
#include "DroneControl.h"
#include "Drone.h"

// --- Constructor

DroneControl::DroneControl() {

  // Setup RPC... something something

}

// --- RPC Functions ---

// Computer Vision
int DroneControl::askHoops() {return 0;}
int DroneControl::askHoopX(int n) {return 0;} // X position on camera
int DroneControl::askHoopY(int n) {return 0;} // Y position on camera
int DroneControl::askHoopH(int n) {return 0;} // Vertical Radius
int DroneControl::askHoopW(int n) {return 0;} // Horizontal Radius

int DroneControl::askQRs() {return 0;}
int DroneControl::askQRX(int n) {return 0;}
int DroneControl::askQRY(int n) {return 0;}
int DroneControl::askQRH(int n) {return 0;}
int DroneControl::askQRW(int n) {return 0;}

// Drone Sensors
int DroneControl::askHeight() {return 0;}
int DroneControl::askTrueAngle() {return 0;}

// Drone Instructions
int DroneControl::instruction(float x, float y, float z, float a) {return 0;}

// ---
