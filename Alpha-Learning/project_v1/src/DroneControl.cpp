#include "ofMain.h"
#include "DroneControl.h"
#include "Drone.h"
#include "settings.h"

DroneControl::DroneControl() {

}

void DroneControl::setup(Drone *_drone) {
  drone = _drone;
}

int DroneControl::keyboard(int key, bool keyPressed) {

  switch (key) {
    case 'W':
    case 'w':
    forwardToggle(keyPressed);
    break;
    case 'A':
    case 'a':
    strafeLeftToggle(keyPressed);
    break;
    case 'S':
    case 's':
    backwardToggle(keyPressed);
    break;
    case 'D':
    case 'd':
    strafeRightToggle(keyPressed);
    break;
    case 'Q':
    case 'q':
    turnLeftToggle(keyPressed);
    break;
    case 'E':
    case 'e':
    turnRightToggle(keyPressed);
    break;
    default:
    case MAC_SPACE_A:
    case MAC_SPACE_B:
    upToggle(keyPressed);
    break;
    case MAC_SHIFT_A:
    case MAC_SHIFT_B:
    downToggle(keyPressed);
    break;
    return false;
    break;
  }

  return true;

}

int DroneControl::command(Drone *drone) {

  drone->upDown(upDownSpeed);
  drone->forwardBackward(forwardBackwardSpeed);
  drone->strafeLeftRight(turnLeftRightSpeed);
  drone->turnLeftRight(strafeLeftRightSpeed);

  if(upDownSpeed > 0) upDownSpeed += 0.01;
  if(upDownSpeed < 0) upDownSpeed -= 0.01;

  if(forwardBackwardSpeed > 0) forwardBackwardSpeed += 0.01;
  if(forwardBackwardSpeed < 0) forwardBackwardSpeed -= 0.01;

  if(turnLeftRightSpeed > 0) turnLeftRightSpeed += 0.01;
  if(turnLeftRightSpeed < 0) turnLeftRightSpeed -= 0.01;

  if(strafeLeftRightSpeed > 0) strafeLeftRightSpeed += 0.01;
  if(strafeLeftRightSpeed < 0) strafeLeftRightSpeed -= 0.01;

  return true;

}

// Manual Drone Control

// Z Control
int DroneControl::upToggle(bool keyPressed) {
  if(!up && !down && keyPressed) {
    printf("Going up.\n");
    up = true;
    upDownSpeed = 0.1;
    return true;
  } else if (up && !keyPressed) {
    printf("Stop going Up.\n");
    up = false;
    upDownSpeed = 0.0;
    return true;
  } else {
    printf("Can't go up.\n");
    return false;
  }
} // Space
int DroneControl::downToggle(bool keyPressed) {
  if(!down && !up && keyPressed) {
    printf("Going down.\n");
    upDownSpeed = -0.1;
    down = true;
    return true;
  } else if (down && !keyPressed) {
    printf("Stop going down.\n");
    down = false;
    upDownSpeed = 0.0;
    return true;
  } else {
    printf("Can't go down.\n");
    return false;
  }
} // Shift

// XY Basic Control
int DroneControl::forwardToggle(bool keyPressed) {
  if(!forward && !backward && keyPressed) {
    printf("Going forward.\n");
    forward = true;
    forwardBackwardSpeed = 0.1;
    return true;
  } else if(forward && !keyPressed) {
    printf("Stop going forward.\n");
    forward = false;
    forwardBackwardSpeed = 0.0;
    return true;
  } else {
    printf("Can't go forward.\n");
    return false;
  }
} // W w
int DroneControl::backwardToggle(bool keyPressed) {
  if(!backward && !forward && keyPressed) {
    printf("Going backward.\n");
    backward = true;
    forwardBackwardSpeed = -0.1;
    return true;
  } else if(backward && !keyPressed) {
    printf("Stop going backward.\n");
    backward = false;
    forwardBackwardSpeed = 0.0;
    return true;
  } else {
    printf("Can't go backward.\n");
    return false;
  }
} // S s

int DroneControl::strafeLeftToggle(bool keyPressed) {
  if(!strafeLeft && !strafeRight && keyPressed) {
    printf("Strafe Left.\n");
    strafeLeft = true;
    strafeLeftRightSpeed = 0.1;
    return true;
  } else if(strafeLeft && !keyPressed) {
    printf("Stop strafing left.\n");
    strafeLeft = false;
    strafeLeftRightSpeed = 0.0;
    return true;
  } else {
    printf("Can't strafe left.\n");
    return false;
  }
} // A a
int DroneControl::strafeRightToggle(bool keyPressed) {
  if(!strafeRight && !strafeLeft && keyPressed) {
    printf("Strafe right.\n");
    strafeRight = true;
    strafeLeftRightSpeed = -0.1;
    return true;
  } else if(strafeRight && !keyPressed) {
    printf("Stop strafing right.\n");
    strafeRight = false;
    strafeLeftRightSpeed = 0.0;
    return true;
  } else {
    printf("Can't strafe Right.\n");
    return false;
  }
} // D d

int DroneControl::turnLeftToggle(bool keyPressed) {
  if(!turnLeft && !turnRight && keyPressed) {
    printf("Turning left.\n");
    turnLeft = true;
    turnLeftRightSpeed = 0.1;
    return true;
  } else if(turnLeft && !keyPressed) {
    printf("Stop turning Left.\n");
    turnLeft = false;
    turnLeftRightSpeed = 0.0;
    return true;
  } else {
    printf("Can't turn left.\n");
    return false;
  }
} // E e
int DroneControl::turnRightToggle(bool keyPressed) {
  if(!turnRight && !turnLeft && keyPressed) {
    printf("Turning right.\n");
    turnRight = true;
    turnLeftRightSpeed = -0.1;
    return true;
  } else if(turnRight && !) {
    printf("Stop turning right.\n");
    turnRight = false;
    turnLeftRightSpeed = 0.0;
    return true;
  } else {
    printf("Can't turn right.\n");
    return false;
  }
} // Q q

int DroneControl::noKeyPressed() {
  up = false;
  down = false;
  upDownSpeed = 0;
  forward = false;
  backward = false;
  forwardBackwardSpeed = 0;
  strafeLeft = false;
  strafeRight = false;
  strafeLeftRightSpeed = 0;
  turnLeft = false;
  turnRight = false;
  turnLeftRightSpeed = 0;

  return true;
}

/*

// XY Advanced Control
int DroneControl::forwardStrafeLeft() {
  printf("Down.\n");
  return true;
} // WA wa
int DroneControl::forwardStrafeRight() {
  printf("Down.\n");
  return true;
} // WD wd

int DroneControl::backwardStrafeLeft() {
  printf("Down.\n");
  return true;
} // SA sa
int DroneControl::backwardStrafeRight() {
  printf("Down.\n");
  return true;
} // SD sd

int DroneControl::turnLeftForward() {
  printf("Down.\n");
  return true;
} // WQ wq
int DroneControl::turnRightForward() {
  printf("Down.\n");
  return true;
} // WE we

int DroneControl::leftSidewaysBackward() {
  printf("Down.\n");
  return true;
} // SQ sq
int DroneControl::rightSidewaysBackward() {
  printf("Down.\n");
  return true;
} // SE se

int DroneControl::strafeLeftTurnLeft() {
  printf("Down.\n");
  return true;
} // QA qa
int DroneControl::strafeLeftTurnRight() {
  printf("Down.\n");
  return true;
} // QD qd

int DroneControl::strafeRightTurnLeft() {
  printf("Down.\n");
  return true;
} // EA ea
int DroneControl::strafeRightTurnRight() {
  printf("Down.\n");
  return true;
} // ED ed

*/
