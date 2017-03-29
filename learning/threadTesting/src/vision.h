#pragma once

#include <iostream>

class Vision : public ofThread {

  public:

    void threadedFunction() {

      // Setup

      //sleep(500);

      cout << "Vision Thread Initialized.\n\r";

      while(isThreadRunning()) {

        // Loop

        cout << "Vision.\n\r";

        //sleep(1000);

      }

    }

};
