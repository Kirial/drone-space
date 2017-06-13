#include "ofMain.h"
#include "settings.h"
#include "DroneControl.h"
#include "DroneRoom.h"
#include "Drone.h"
#include "DroneAI.h"

DroneAI::DroneAI(Drone *_drone, DroneRoom *_droneroom, DroneControl *_dronecontrol) {

  drone = _drone;
  droneroom = _droneroom;
  dronecontrol = _dronecontrol;

  startAllTrajectories();

  // Initial Takeoff Trajectory

  landingwaypoint.point = droneroom->getLandingWaypoint();
  landingwaypoint.flightmode = TAKEOFF;

  addTakeoffPoint(drone->node.getPosition(), NOTFLYING);
  addTakeoffPoint(landingwaypoint.point, landingwaypoint.flightmode);
  addTakeoffPoint(droneroom->hoops[0].getEntryPosition(), NORMAL);
  finishTakeoffTrajectory();

  // Initial Loop Trajectory

  for(int i = 0; i < HOOP_COUNT; i++) {
    addLoopPoint(droneroom->hoops[i].getEntryPosition(), NORMAL);
    addLoopPoint(droneroom->hoops[i].getExitPosition(), STEADY);
  }
  completeLoopTrajectory();

  optimizeTrajection(loopCurrent,loopHead,&loopTrajectoryCount);

  // Initial Landing Trajectory

  addLandingPoint(droneroom->hoops[HOOP_COUNT-1].getExitPosition(),NORMAL);
  addLandingPoint(landingwaypoint.point,NORMAL);
  addLandingPoint(drone->node.getPosition(),LANDING);
  finishLandingTrajectory();

}

void DroneAI::draw() {
  drawLoopTrajectory();
  drawTakeoffTrajectory();
  drawLandingTrajectory();
}

// Calculate Trajection

void DroneAI::optimizeTrajection(Trajectory *currentPtr, Trajectory *headPtr, int *count) {

  printf("Starting to optimize trajection\n");

  //Hoop *sortedHoops[HOOP_COUNT];

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

    int checkHoops = HOOP_COUNT;
    int hoopsToBeChecked[HOOP_COUNT];

    for(int j = 0; j < HOOP_COUNT; j++) {

      hoopsToBeChecked[j] = false;

    }

    for(int j = 0; j < HOOP_COUNT;j++) {

      P = droneroom->hoops[j].getPosition();

      AP = P - A;

      APdist = AP.length();

      APmin = sqrt(pow(ABdist,2) + pow(HOOP_SAFETYDISTANCE,2));

      if(APmin < APdist) {
        printf("Hoop %i is is too far away.\n",j);
        checkHoops--;
        continue;
      }

      BAPangle = AP.angle(AB);

      if(BAPangle > 90) {
        printf("Hoop %i angle is too large.\n",j);
        checkHoops--;
        continue;
      }



      float pPdist = sin(BAPangle) * APdist;

      if(pPdist > HOOP_SAFETYDISTANCE) {
        printf("Hoop %i is is outside the safety distance.\n",j);
        continue;
      }

      printf("Hoop %i distance: %f, angle: %f.\n", j, AP.length(), AP.angle(AB));

      hoopsToBeChecked[j] = true;



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

// Loop
int DroneAI::addLoopPoint(ofVec3f point, FlightMode flight) {

  //printf("Adding Loop Trajectory Point - x: %f, y: %f, y: %f.\n",point.x,point.y,point.z);

  loopHead->point = point;
  loopHead->flightmode = flight;

  loopHead = loopHead->next;

  loopTrajectoryCount++;

  return true;

}
int DroneAI::insertLoopPoint(ofVec3f point, FlightMode flight) {

  loopHead->point = point;
  loopHead->flightmode = flight;

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

// Takeoff
int DroneAI::addTakeoffPoint(ofVec3f point, FlightMode flight) {

  //printf("Adding Loop Trajectory Point - x: %f, y: %f, y: %f.\n",point.x,point.y,point.z);

  takeoffHead->point = point;
  takeoffHead->flightmode = flight;

  takeoffHead = takeoffHead->next;

  takeoffTrajectoryCount++;

  return true;

}
int DroneAI::insertTakeoffPoint(ofVec3f point, FlightMode flight) {

  takeoffHead->point = point;
  takeoffHead->flightmode = flight;

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
  takeoffHead->prev->next = NULL;
  return true;
}

// Landing
int DroneAI::addLandingPoint(ofVec3f point, FlightMode flight) {

  //printf("Adding Loop Trajectory Point - x: %f, y: %f, y: %f.\n",point.x,point.y,point.z);

  landingHead->point = point;
  landingHead->flightmode = flight;

  landingHead = landingHead->next;

  landingTrajectoryCount++;

  return true;

}
int DroneAI::insertLandingPoint(ofVec3f point, FlightMode flight) {

  landingHead->point = point;
  landingHead->flightmode = flight;

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
  landingHead->prev->next = NULL;
  return true;
}
