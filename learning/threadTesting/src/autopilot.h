#ifndef AUTOPILOT_H
#define AUTOPILOT_H

class Autopilot : public ofThread {

public:

  Autopilot() { // Setup

    cout << "Autopilot initialized";

  }

  void threadedFunction() { // Loop

    while(isThreadRunning()) {

    }

  }

};

#endif
