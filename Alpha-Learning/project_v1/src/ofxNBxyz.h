#ifndef OFXNBXYZ_H
#define OFXNBXYZ_H

ofQuaternion setVectorOrientation(ofVec3f vector);
ofQuaternion setVectorOrientation(float x, float y, float z);
ofQuaternion setVectorOrientationPlane(ofVec3f vector);
ofQuaternion setVectorOrientationPlane(float x, float y, float z);

class Wirebox {

  public:

    Wirebox();
    void draw();
    void drawNodes();
    void setOrientation(ofQuaternion ofQ);
    void setScale(float scale);
    void setParent(ofNode *node);
    void set(float X, float Y, float Z);

    ofVec3f inside(ofVec3f position); // Return a vector to get back in.
    ofVec3f outside(ofVec3f position); // Return a vector to get back out.

    ofNode node;

  private:

    float X = 0;
    float Y = 0;
    float Z = 0;
    float scale = 1;

    ofNode cornerNodes[8];
    static const int corners = 8;

    ofNode positionNode;

};

class Wireframe {

  public:

  private:

};

#endif /* end of include guard: OFXNBXYZ_H */
