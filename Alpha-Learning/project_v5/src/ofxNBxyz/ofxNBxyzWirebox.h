#ifndef WIREBOX_H
#define WIREBOX_H

#include "ofMain.h"

class Wirebox {

  public:

    Wirebox();
    void draw();
    void drawNodes();
    void set(float X, float Y, float Z);

    float inside(ofVec3f position, ofVec3f *result); // Return a vector to get back in.
    float outside(ofVec3f position, ofVec3f *result); // Return a vector to get back out.

    ofNode node;

  private:

    float X = 0;
    float Y = 0;
    float Z = 0;

    static const int corners = 8;
    ofNode cornerNodes[corners];

    ofNode positionNode;

};

#endif /* end of include guard: WIREBOX_H */
