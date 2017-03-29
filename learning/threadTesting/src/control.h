#pragma once

#include <iostream>

class Control : public ofThread {

  public:

    void threadedFunction() {

      // Setup

      cout << "Control Thread Initialized.\n\r";

      while(isThreadRunning()) {

        // Loop

        cout << "Control.\n\r";

        //sleep(1000);

      }

    }

};
