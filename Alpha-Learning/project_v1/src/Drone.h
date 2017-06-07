#ifndef DRONE_H
#define DRONE_H

#include "ofMain.h"

#define DRONE_HITBOX_H 120
#define DRONE_HITBOX_L 440
#define DRONE_HITBOX_W 440

class Drone {

public:

  Drone();

  void draw();
  void drawHitbox();

  // Basic Movement
  int upDown(float distance);
  int forwardBackward(float distance);
  int strafeLeftRight(float distance);
  int turnLeftRight(float angle);

  // Control Movement

  void moveToLandingArea(ofNode landingArea);

  ofVec3f getPosition();

  /*
  int set(float x, float y, float z);
  int setYaw(float y);
  int setRoll(float r);
  int setPitch(float p);

  int move(float x, float y, float z);

  int yaw(float y);
  int roll(float r);
  int pitch(float p);
  */

  ofNode node;


private:

  // Original Positions
  float originX; // X
  float originY; // Up / Down
  float originZ; // Z

  // Current Positions
  float x;
  float y;
  float z;

  // Rotation Offset
  float yawOffset;
  float rollOffset;
  float pitchOffset;

  // Graphical Elements
  ofBoxPrimitive hitbox;

};

#endif /* end of include guard: DRONE_H */
