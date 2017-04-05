#ifndef CONTROL_H
#define CONTROL_H

#include "cli.h"

class Control : public ofThread {

public:

  Control(Cli *_cli) { // Setup

    cli = _cli;

    cout << "Control Thread Initialized.\n\r";

    sleep(10);

  }

  void threadedFunction() { // Loop

    while(isThreadRunning()) {

      // Loop

      cli.addMessage("Control.");

      sleep(20);

    }

  }

private:

  Cli &cli;

};

#endif
