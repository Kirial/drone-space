#include "ofMain.h"
#include "settings.h"
#include "DroneControl.h"
#include "DroneRoom.h"
#include "Drone.h"
#include "DroneAI.h"

bool sortByDist(const HoopDistance &lhs, const HoopDistance &rhs) { return lhs.intDist < rhs.intDist; }

DroneAI::DroneAI(Drone *_drone, DroneRoom *_droneroom, DroneControl *_dronecontrol) {

  drone = _drone;
  droneroom = _droneroom;
  dronecontrol = _dronecontrol;

  trueAngleO.setGlobalPosition(0,0,0);
  trueAngleA.setParent(trueAngleO);
  trueAngleA.move(100,0,0);

  started = false;

  startAI();

}

// General Functions

int DroneAI::startAI() {

  if(started) return false;

  started = true;

  return true;

}
int DroneAI::stopAI() {

  if(!started) return false;

  started = false;

  return true;

}

void DroneAI::update() {

  if(!started) return;

  // Get Drone Information

    // Get True Angle

    getTrueAngleOffset();

    // Get Hoops

    getHoops();

    // QRs

    getQRs();

  // Calculate Position

    // 1. x,y,z,a,A

    // 2. HoopBased Position

    // 3. QR Code Based Position

  // ---

  if(drone->getDroneMode() == MANUAL) {

    // Hold or manual

    drone->update();

    droneInstruct();

    return;

  }

  if(drone->getDroneMode() == HOLD) {

    drone->update();

    droneInstruct();

    return;

  }

  if(ofGetElapsedTimeMillis() > DEADLINE*1000) {

    // Time run out, land!

    if(!LANDED) droneLand();

  } else if(ofGetElapsedTimeMillis() > STARTLANDING*1000) {

    // Start Landing

    if(!(drone->getDroneMode() != LANDING)) {

      // Calculate Landing Trajectory

    }

    if(!(drone->getDroneMode() != LANDED)) {

      // Get to landing waypoint

      droneLanding();

    } else {

      // Land!

      droneLand();

    }

  } else if(drone->getDroneMode() == TAKEOFF) {

    // Takeoff

    droneTakeoff();

  } else if(drone->getDroneMode() == LANDED) {

    // Start the Drone

    droneStart();

  } else {

    // If position is unknown, look for position

    // Loop

    droneLoop();

  }

  // --- Drone Instructions ---

  // Real

  //instruction();

  // Virtual

  drone->update();

  droneInstruct();

  return;

}

void DroneAI::draw() {
  drawLoopTrajectory();
  drawTakeoffTrajectory();
  drawLandingTrajectory();
  drawTrueAngle();
}

// Drone AI Modes

void DroneAI::droneStart() {

  startAllTrajectories();

  // Initial Takeoff Trajectory

  landingwaypoint.point = droneroom->getLandingWaypoint();
  landingwaypoint.flightmode = NORMAL;

  addTakeoffPoint(droneroom->getLandingPlatform(), NORMAL, LANDED);
  addTakeoffPoint(droneroom->getLandingWaypoint(), NORMAL, TAKEOFF);
  addTakeoffPoint(droneroom->hoops[0].getEntryPosition(), NORMAL, AUTONOMOUS);
  finishTakeoffTrajectory();

  optimizeTrajectory(takeoffCurrent, takeoffHead, &takeoffTrajectoryCount);

  // Initial Loop Trajectory

  for(int i = 0; i < HOOP_COUNT; i++) {
    addLoopPoint(droneroom->hoops[i].getEntryPosition(), NORMAL, AUTONOMOUS);
    addLoopPoint(droneroom->hoops[i].getExitPosition(), STEADY, AUTONOMOUS);
  }

  completeLoopTrajectory();

  optimizeTrajectory(loopCurrent, loopHead, &loopTrajectoryCount);

  // Reset Timer

  printf("Taking off!\n");

  takeoffCurrent = takeoffTail->next;

  drone->setDroneMode(TAKEOFF);
  drone->setFlightMode(takeoffCurrent->flightmode);
  drone->setDestination(takeoffCurrent->point);

  printf("Destination - x: %f, y: %f, y: %f.\n",drone->getDestination().x,drone->getDestination().y,drone->getDestination().z);

  printFlightMode(drone->getFlightMode());
  printDroneMode(drone->getDroneMode());


}
void DroneAI::droneTakeoff() {

  if(drone->getDestinationDistance() < WAYPOINT_DISTANCE) {

    if(!takeoffCurrent->end) {

      takeoffCurrent = takeoffCurrent->next;

      drone->setDestination(takeoffCurrent->point);
      drone->setFlightMode(takeoffCurrent->flightmode);
      drone->setDroneMode(takeoffCurrent->dronemode);

      printFlightMode(drone->getFlightMode());
      printDroneMode(drone->getDroneMode());

      printf("New Takeoff Waypoint.\n");

      printf("End Destination - x: %f, y: %f, y: %f.\n",drone->getDestination().x,drone->getDestination().y,drone->getDestination().z);

    } else {

      printf("Took Off!\n");

      loopCurrent = loopHead;
      loopCurrent = loopCurrent->next;

      drone->setFlightMode(loopCurrent->flightmode);
      drone->setDestination(loopCurrent->point);
      drone->setDroneMode(loopCurrent->dronemode);

      printFlightMode(drone->getFlightMode());
      printDroneMode(drone->getDroneMode());

      printf("Startin Loop!\n");

      printf("Destination - x: %f, y: %f, y: %f.\n",drone->getDestination().x,drone->getDestination().y,drone->getDestination().z);

    }

  }

}
void DroneAI::droneLoop() {

  //printf("Looping.\n");

  if(drone->getDestinationDistance() < WAYPOINT_DISTANCE) {

    printf("New Loop Waypoint.\n");

    loopCurrent = loopCurrent->next;

    drone->setFlightMode(loopCurrent->flightmode);
    drone->setDestination(loopCurrent->point);
    drone->setDroneMode(loopCurrent->dronemode);

    printFlightMode(drone->getFlightMode());
    printDroneMode(drone->getDroneMode());

    printf("Destination - x: %f, y: %f, y: %f.\n",drone->getDestination().x,drone->getDestination().y,drone->getDestination().z);

  }

}
void DroneAI::droneLanding() {

  if(!calculatedLandingTrajectory) {

    printf("Starting to land!\n");

    // Initial Landing Trajectory

    addLandingPoint(drone->node.getPosition(),NORMAL,AUTONOMOUS);
    addLandingPoint(droneroom->getLandingWaypoint(),NORMAL,AUTONOMOUS);
    addLandingPoint(droneroom->getLandingPlatform(),NORMAL,LANDING);
    finishLandingTrajectory();

    landingCurrent = landingTail->next;

    calculatedLandingTrajectory = true;

    drone->setFlightMode(landingCurrent->flightmode);
    drone->setDestination(landingCurrent->point);

  }

  if(drone->getDestinationDistance() < WAYPOINT_DISTANCE) {

    if(!landingCurrent->end) {

      printf("Landing Waypoint.\n");

      printf("Destination - x: %f, y: %f, y: %f.\n",drone->getDestination().x,drone->getDestination().y,drone->getDestination().z);

      landingCurrent = landingCurrent->next;

      drone->setFlightMode(landingCurrent->flightmode);
      drone->setDestination(landingCurrent->point);

    } else if(drone->getDroneMode() != LANDED) {

      printf("Landed!\n");

      printf("Destination - x: %f, y: %f, y: %f.\n",drone->getDestination().x,drone->getDestination().y,drone->getDestination().z);

      drone->setDroneMode(LANDED);

    }
  }
}
void DroneAI::droneLand() {

  if(drone->getDroneMode() != LANDED) {
    printf("Landing!\n");
    drone->setDroneMode(LANDED);
  } else {
    printf("Landed!\n");
  }
}
void DroneAI::droneInstruct() {

  // Only turn left or right

  //printf("DestinationOffset - x: %f, y: %f, z: %f.\n", );

  if(drone->getAngleOffset() > DRONE_ANGLE_OFFSET && drone->getDroneMode() != TAKEOFF && drone->getDroneMode() != LANDING) {

    // Only turning

    //printf("Turning: %f.\n", drone->getAngleOffset());

  }

  else if(drone->getDroneMode() == TAKEOFF || drone->getDroneMode() == LANDING) {

    // Not turning

    //printf("Moving - x: %f, y: %f, z: %f.\n", drone->getDirection().x, drone->getDirection().y, drone->getDirection().z);

  }

  else {

    // Normal

    //printf("Moving - x: %f, y: %f, z: %f, a: .\n", drone->getDirection().x, drone->getDirection().y, drone->getDirection().z, drone->getAngleOffset());

  }

  drone->instruction();

}

// --- Trajectory Functions ---

// Optimize Trajectory
void DroneAI::optimizeTrajectory(Trajectory *currentPtr, Trajectory *headPtr, int *count) {

  printf("Starting to optimize trajection\n");

  Trajectory *ptr = currentPtr;

  ofVec3f A, B, P, AB, AP;

  float APdist, APmin, ABdist, pPdist, BAPangle;

  for(int i = 0; i < *count; i++) {

    printf("Loop Iteration: %i.\n", i);

    A = ptr->point;

    //printf("Point A - x:%f, y:%f, z:%f.\n", A.x,A.y,A.z);

    ptr = ptr->next;

    B = ptr->point;

    //printf("Point B - x:%f, y:%f, z:%f.\n", B.x,B.y,B.z);

    if(ptr->flightmode == STEADY) {
      printf("Flightmode is STEADY.\n");
      continue;
    }

    AB = B - A;

    ABdist = AB.length();

    printf("Flight distance AB: %f.\n", ABdist);

    int checkHoops = 0;

    HoopDistance hoopsToBeChecked[HOOP_COUNT];

    for(int j = 0; j < HOOP_COUNT; j++) {

      hoopsToBeChecked[j].n = j;
      hoopsToBeChecked[j].intDist = 2147483647;
      hoopsToBeChecked[j].distToOrigin = 0;
      hoopsToBeChecked[j].distToTrajectory = 0;

    }

    for(int j = 0; j < HOOP_COUNT;j++) {

      P = droneroom->hoops[j].getPosition();

      AP = P - A;

      APdist = AP.length();

      APmin = sqrt(pow(ABdist,2) + pow(HOOP_SAFETYDISTANCE,2));

      if(APmin < APdist) {
        printf("Hoop %i is is too far away.\n",j);
        //checkHoops--;
        continue;
      }

      BAPangle = AP.angle(AB);

      if(BAPangle > 90) {
        printf("Hoop %i angle is too large.\n",j);
        //checkHoops--;
        continue;
      }

      float pPdist = sin(ofDegToRad(BAPangle)) * APdist;

      if(pPdist > HOOP_SAFETYDISTANCE) {
        printf("Hoop %i is is outside the safety distance.\n",j);
        //checkHoops--;
        continue;
      }

      printf("Hoop %i distance: %f, angle: %f.\n", j, AP.length(), AP.angle(AB));

      // Push to array

      hoopsToBeChecked[j].distToOrigin = APdist;
      hoopsToBeChecked[j].distToTrajectory = pPdist;
      hoopsToBeChecked[j].intDist = (int)APdist;
      checkHoops++;

    }

    sort(&hoopsToBeChecked[0], &hoopsToBeChecked[HOOP_COUNT], sortByDist);

    printf("Check Hoops Count: %i\n", checkHoops);

    for(int j = 0; j < checkHoops; j++) {

      printf("Hoop %i with %i int dist, has distance %f to origin, and distance to trajectry %f.\n", hoopsToBeChecked[j].n, hoopsToBeChecked[j].intDist, hoopsToBeChecked[j].distToOrigin, hoopsToBeChecked[j].distToTrajectory);

    }

  }

}

// Draw Trajectories
void DroneAI::drawLoopTrajectory() {

  ofSetColor(ofColor::black);

  Trajectory *ptr = loopTail;

  ofVec3f A, B;

  for(int i = 0; i < loopTrajectoryCount; i++) {

    A = ptr->point;
    B = ptr->next->point;

    ofDrawArrow(A,B);

    ptr = ptr->next;

  }
}
void DroneAI::drawTakeoffTrajectory() {

  ofSetColor(ofColor::green);

  Trajectory *ptr = takeoffTail;

  ofVec3f A;
  ofVec3f B;

  for(int i = 0; i < takeoffTrajectoryCount-1; i++) {

    A = ptr->point;
    B = ptr->next->point;

    ofDrawArrow(A,B);

    ptr = ptr->next;

  }

  ofSetColor(ofColor::black);

}
void DroneAI::drawLandingTrajectory() {

  ofSetColor(ofColor::red);

  Trajectory *ptr = landingTail;

  ofVec3f A;
  ofVec3f B;

  for(int i = 0; i < landingTrajectoryCount-1; i++) {

    A = ptr->point;
    B = ptr->next->point;

    ofDrawArrow(A,B);

    ptr = ptr->next;

  }

  ofSetColor(ofColor::black);
}

// Start Trajectories
void DroneAI::startAllTrajectories() {

  startLoopTrajectory();
  startTakeoffTrajectory();
  startLandingTrajectory();

}
void DroneAI::startLoopTrajectory() {

  printf("Starting Loop Trajectory\n");

  // Loop Trajectory

  for(int i = 0; i < LOOP_TRAJECTORY_MAX-1; i++) {
    loopTrajectory[i].next = &loopTrajectory[i+1];
    loopTrajectory[i+1].prev = &loopTrajectory[i];
  }

  loopTrajectory[LOOP_TRAJECTORY_MAX-1].next = &loopTrajectory[0];
  loopTrajectory[0].prev = &loopTrajectory[LOOP_TRAJECTORY_MAX-1];

  loopHead = &loopTrajectory[0];
  loopTail = &loopTrajectory[0];
  loopCurrent = &loopTrajectory[0];

  loopTrajectoryCount = 0;

}
void DroneAI::startTakeoffTrajectory() {

  // Takeoff Trajectory

  for(int i = 0; i < TAKEOFF_TRAJECTORY_MAX-1; i++) {
    takeoffTrajectory[i].next = &takeoffTrajectory[i+1];
    takeoffTrajectory[i+1].prev = &takeoffTrajectory[i];
  }

  takeoffTrajectory[TAKEOFF_TRAJECTORY_MAX-1].next = &takeoffTrajectory[0];
  takeoffTrajectory[0].prev = &takeoffTrajectory[TAKEOFF_TRAJECTORY_MAX-1];

  takeoffHead = &takeoffTrajectory[0];
  takeoffTail = &takeoffTrajectory[0];
  takeoffCurrent = &takeoffTrajectory[0];

  takeoffTrajectoryCount = 0;

}
void DroneAI::startLandingTrajectory() {

  // Landing Trajectory

  for(int i = 0; i < LANDING_TRAJECTORY_MAX-1; i++) {
    landingTrajectory[i].next = &landingTrajectory[i+1];
    landingTrajectory[i+1].prev = &landingTrajectory[i];
  }

  landingTrajectory[LANDING_TRAJECTORY_MAX-1].next = &landingTrajectory[0];
  landingTrajectory[0].prev = &landingTrajectory[LANDING_TRAJECTORY_MAX-1];

  landingHead = &landingTrajectory[0];
  landingTail = &landingTrajectory[0];
  landingCurrent = &landingTrajectory[0];

  landingTrajectoryCount = 0;

}

// Loop Trajectory
int DroneAI::addLoopPoint(ofVec3f point, FlightMode flightmode, DroneMode dronemode) {

  printf("Adding Loop Trajectory Point - x: %f, y: %f, y: %f.\n",point.x,point.y,point.z);

  loopHead->point = point;
  loopHead->flightmode = flightmode;
  loopHead->dronemode = dronemode;

  loopHead = loopHead->next;

  loopTrajectoryCount++;

  return true;

}
int DroneAI::insertLoopPoint(ofVec3f point, FlightMode flightmode, DroneMode dronemode) {

  loopHead->point = point;
  loopHead->flightmode = flightmode;
  loopHead->dronemode = dronemode;

  Trajectory *tmpPtrA = loopCurrent->next;
  Trajectory *tmpPtrB = loopHead->prev;
  Trajectory *tmpPtrC = loopHead->next;

  loopCurrent->next = loopHead;
  loopHead->next = tmpPtrA;
  tmpPtrB->next = tmpPtrC;

  loopHead->prev = loopCurrent;
  tmpPtrA->prev = loopHead;
  tmpPtrC->prev = tmpPtrB;

  loopHead = tmpPtrC;

  loopTrajectoryCount++;

  return true;

}
int DroneAI::completeLoopTrajectory() {

  loopHead = loopHead->prev;

  loopHead->next = loopTail;
  loopTail->prev = loopHead;

  return true;

}

// Takeoff Trajectory
int DroneAI::addTakeoffPoint(ofVec3f point, FlightMode flightmode, DroneMode dronemode) {

  //printf("Adding Loop Trajectory Point - x: %f, y: %f, y: %f.\n",point.x,point.y,point.z);

  takeoffHead->point = point;
  takeoffHead->flightmode = flightmode;
  takeoffHead->dronemode = dronemode;

  takeoffHead = takeoffHead->next;

  takeoffTrajectoryCount++;

  return true;

}
int DroneAI::insertTakeoffPoint(ofVec3f point, FlightMode flightmode, DroneMode dronemode) {

  takeoffHead->point = point;
  takeoffHead->flightmode = flightmode;
  takeoffHead->dronemode = dronemode;

  Trajectory *tmpPtrA = takeoffCurrent->next;
  Trajectory *tmpPtrB = takeoffHead->prev;
  Trajectory *tmpPtrC = takeoffHead->next;

  takeoffCurrent->next = takeoffHead;
  takeoffHead->next = tmpPtrA;
  tmpPtrB->next = tmpPtrC;

  takeoffHead->prev = takeoffCurrent;
  tmpPtrA->prev = takeoffHead;
  tmpPtrC->prev = tmpPtrB;

  takeoffHead = tmpPtrC;

  takeoffTrajectoryCount++;

  return true;

}
int DroneAI::finishTakeoffTrajectory() {
  takeoffHead->prev->end = true;
  return true;
}

// Landing Trajectory
int DroneAI::addLandingPoint(ofVec3f point, FlightMode flightmode, DroneMode dronemode) {

  //printf("Adding Loop Trajectory Point - x: %f, y: %f, y: %f.\n",point.x,point.y,point.z);

  landingHead->point = point;
  landingHead->flightmode = flightmode;
  landingHead->dronemode = dronemode;

  landingHead = landingHead->next;

  landingTrajectoryCount++;

  return true;

}
int DroneAI::insertLandingPoint(ofVec3f point, FlightMode flightmode, DroneMode dronemode) {

  landingHead->point = point;
  landingHead->flightmode = flightmode;
  landingHead->dronemode = dronemode;

  Trajectory *tmpPtrA = landingCurrent->next;
  Trajectory *tmpPtrB = landingHead->prev;
  Trajectory *tmpPtrC = landingHead->next;

  landingCurrent->next = landingHead;
  landingHead->next = tmpPtrA;
  tmpPtrB->next = tmpPtrC;

  landingHead->prev = landingCurrent;
  tmpPtrA->prev = landingHead;
  tmpPtrC->prev = tmpPtrB;

  landingHead = tmpPtrC;

  loopTrajectoryCount++;

  return true;

}
int DroneAI::finishLandingTrajectory() {
  landingHead->prev->end = true;
  return true;
}

// --- Anti Collision ---

ofVec3f DroneAI::antiCollision() {}

// --- Real Drone Functions ---

void DroneAI::getHoops() {

  drone->resetHoops();

  int hoopsNow = dronecontrol->askHoops();

  int binary, x, y, h, n = 1;

  for(int i = 0; i < HOOP_COUNT * 2; i++) {

    if(binary & hoopsNow) {

      x = dronecontrol->askHoopX(binary);
      y = dronecontrol->askHoopY(binary);
      h = dronecontrol->askHoopH(binary);
      n = i + 1;

      if(n > 6) n = false;

      drone->addHoop(x,y,h,n);

    }

    binary = binary * 2;

  }

}
void DroneAI::getQRs() {

  drone->resetQRs();

  int QRsNow = dronecontrol->askQRs();

  int binary, x, y, h, n = 1;

  for(int i = 0; i < (HOOP_COUNT + QR_REAL_COUNT); i++) {

    if(binary & QRsNow) {

      x = dronecontrol->askQRX(binary);
      x = dronecontrol->askQRY(binary);
      x = dronecontrol->askQRH(binary);
      n = i + 1;

      drone->addQR(x,y,h,n);

    }

  }

}
float DroneAI::getTrueAngleOffset() {

  float newTrueAngle = dronecontrol->askTrueAngle();

  trueAngleO.rotate(trueAngle-newTrueAngle,0,1,0);

  trueAngle = newTrueAngle;

  return trueAngle;

}

// --- Draw Drone Information ---
