#include <iostream>

#include "ClassB.h"
#include "ClassA.h"

ClassB::ClassB() {

  //myPersonalId = "1337";

}


ClassB* ClassB::getClassB() {

  return this;

}

void ClassB::setClassA(ClassA* ClassAptr_) {

  ClassAptr = ClassAptr_;

}

void ClassB::setMyPersonalId(char* string) {

  myPersonalId = string;

}

void ClassB::helloWorld() {

  std::cout << "Hello, World! I'm class B." << myPersonalId << '\n';

}
