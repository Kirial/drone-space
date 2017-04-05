#pragma once

class ClassA;

class ClassB {

public:

  ClassB();

  ClassB* getClassB();

  void setClassA(ClassA* ClassAptr_);

  void setMyPersonalId(char* string);

  void helloWorld();

private:

protected:

  ClassA* ClassAptr;

  char* myPersonalId;

};
