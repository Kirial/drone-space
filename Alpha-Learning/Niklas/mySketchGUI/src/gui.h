#pragma once

#include "ofMain.h"

enum Function {
  PushFunction,
  ReleaseFunction,
  HoverFunction,
};

class Button {

  public:

    Button();

    void set(int w, int h, int x, int y, ofColor fillColor, ofColor fontColor, string text, ofTrueTypeFont *font);

    void draw();

    void setFunction(Function function, int (*functionPtr)());

    void setHoverAppearance(ofColor hoverFillColor, ofColor hoverFontColor);

    void move(int x, int y);

    int push(int x, int y, int button);
    int release(int x, int y, int button);
    int hover(int x, int y);

    int empty();

  private:

    // Appearance
    int w;
    int h;
    int x;
    int y;

    ofColor fillColor;
    ofColor fontColor;
    ofColor hoverFillColor;
    ofColor hoverFontColor;
    ofTrueTypeFont *font;

    string text;
    int textOffsetX;
    int textOffsetY;
    int textW;
    int textH;

    ofRectangle rect;

    // Internal

    int hovering = 0;

    // Function Pointers
    int pushFuncSet = false;
    int releaseFuncSet = false;
    int hoverFuncSet = false;

    int (*pushFuncPtr)();
    int (*releaseFuncPtr)();
    int (*hoverFuncPtr)();

    //Bitmap

};
