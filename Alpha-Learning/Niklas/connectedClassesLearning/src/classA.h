#pragma once

class ClassB;

class ClassA {

public:

  ClassA();

  ClassA* getClassA();

  void setClassB(ClassB* ClassBptr_);

  void talkB();

private:

protected:

  ClassB* ClassBptr;


};
