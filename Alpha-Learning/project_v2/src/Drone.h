 #ifndef DRONE_H
#define DRONE_H

#include "ofMain.h"

enum DroneMode {READY, HOLD, AUTONOMOUS, MANUAL, LANDED};

enum FlightMode {FAST, NORMAL, STEADY, TAKEOFF, LANDING, NOTFLYING};

class Drone {

public:

  Drone();

  ofVec3f getPosition();

  ofNode node;

  FlightMode flightmode;

  DroneMode dronemode;

private:

  ofBoxPrimitive box;

};

#endif /* end of include guard: DRONE_H */
