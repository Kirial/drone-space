#ifndef CLI_H
#define CLI_H

#define MESSAGE_BUFFER 64

class Cli : public ofThread {

public:

  Cli() { // Setup

    messagesHead = 0;
    messagesTail = 0;

    cout << "Command Line Interface Initialized.";

  }

  void threadedFunction() { // Loop

    if(isThreadRunning()) {

      if(messagesHead != messagesTail) {

        printMessage();

      } else {

        sleep(20);

      }

    }

  }

  void addMessage(char *string) {

    messages[messagesTail] = string;

    messagesHead++;

    if(messagesHead < MESSAGE_BUFFER-1) messagesHead = 0;

  }

private:

  int messagesHead;
  int messagesTail;

  char* messages[MESSAGE_BUFFER];

  void printMessage() {

    print(messages[messagesTail]);

    messagesTail++;

    if(messagesTail < MESSAGE_BUFFER-1) messagesTail = 0;

  }

  void print(char* string) {

    cout << string;

  }

};

#endif
