#include <iostream>

#include "classA.h"
#include "classB.h"

using namespace std;

ClassA::ClassA() {

  cout << "Class A initialized";

}

ClassA* ClassA::getClassA() {

  return this;

}

void ClassA::setClassB(ClassB* ClassBptr_) {

  ClassBptr = ClassBptr_;

}

void ClassA::talkB() {

  ClassBptr->helloWorld();

}
