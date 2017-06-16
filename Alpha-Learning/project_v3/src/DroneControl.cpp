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
int DroneControl::askHoop() {}
int DroneControl::askHoopX(int n) {} // X position on camera
int DroneControl::askHoopY(int n) {} // Y position on camera
int DroneControl::askHoopH(int n) {} // Vertical Radius
int DroneControl::askHoopW(int n) {} // Horizontal Radius

int DroneControl::askQR() {}
int DroneControl::askQRX(int n) {}
int DroneControl::askQRY(int n) {}
int DroneControl::askQRH(int n) {}
int DroneControl::askQRW(int n) {}

// Drone Sensors
int DroneControl::askHeight() {}
int DroneControl::askTrueAngle() {}

// Drone Instructions
int DroneControl::instruction(float x, float y, float z, float a) {}

// ---
