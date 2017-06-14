#include "ofMain.h"
#include "settings.h"
#include "DroneControl.h"
#include "Drone.h"

// --- Constructor

DroneControl::DroneControl(Drone *_drone) {

  Drone = _drone;
  DroneRoom = _droneroom;

  // Setup RPC... something something

}

// --- RPC Functions ---

// Computer Vision
int DroneControl::askHoop() {}
int DroneControl::askHoopX(int n) {} // X position on camera
int DroneControl::askHoopY(int n) {} // Y position on camera
int DroneControl::askHoopRa(int n) {} // Vertical Radius
int DroneControl::askHoopRb(int n) {} // Horizontal Radius

int DroneControl::askQR() {}
int DroneControl::askQRX(int n) {}
int DroneControl::askQRY(int n) {}

// Drone Sensors
int DroneControl::askHeight() {}
int DroneControl::askMagnetometerOrientation() {}

// Drone Instructions
int DroneControl::tellMove(int x, int y, int z) {}
int DroneControl::tellTurn(int a) {}
int DroneControl::tellSetSpeed(int ms) {}
int DroneControl::tellForceMove(int x, int y, int z) {}
int DroneControl::tellForceTurn(int a) {}
int DroneControl::tellForceSetSpeed(int ms) {}

// ---

// --- Virtual Drone Functions ---

int DroneControl::move(float x, float y, float z) {}
int DroneControl::turn(float a) {}
int DroneControl::setPosition(float x, float y, float z) {}
int DroneControl::setTurn(float a) {}
int DroneControl::setDroneSensorHeight(float h) {}
