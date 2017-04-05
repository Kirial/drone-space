#ifndef VISION_H
#define VISION_H

class Vision : public ofThread {

  public:

    Vision() { // Setup

      cout << "Vision Thread Initialized.\n\r";

    }

    void threadedFunction() { // Loop

      while(isThreadRunning()) {

        // Loop

        //cli.addMessage("Vision.");

        sleep(20);

      }

    }

};

#endif
