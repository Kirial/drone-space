#ifndef FLIGHT_H
#define FLIGHT_H

class ARDrone {

public:

  int askYaw() {return 0;}
  int askRoll() {return 0;}
  int askPitch() {return 0;}
  int askHeight() {return 0;}
  int instruct(float x, float y, float z, float a) {return 0;}
  int land() {return 0;}
  int takeoff() {return 0;}

};

#endif /* end of include guard: FLIGHT_H */
