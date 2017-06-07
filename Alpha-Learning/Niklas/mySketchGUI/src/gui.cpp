#include "gui.h"

Button::Button() {

}

void Button::set(

  int _w,
  int _h,
  int _x,
  int _y,
  ofColor _fillColor,
  ofColor _fontColor,
  string _text,
  ofTrueTypeFont *_font

) {

    w = _w;
    h = _h;
    x = _x;
    y = _y;

    rect.x = x;
    rect.y = y;
    rect.width = w;
    rect.height = h;

    fillColor = hoverFillColor = _fillColor;
    fontColor = hoverFontColor = _fontColor;

    text = _text;

    font = _font;

    ofRectangle textBox = font->getStringBoundingBox(text,0,0);
    textOffsetX = w/2 - textBox.width/2;
    textOffsetY = h/2 + textBox.height/2;



}

void Button::draw() {

  if(!hovering) {

    ofSetColor(fillColor);
    ofFill();
    ofDrawRectangle(rect);
    ofSetColor(fontColor);
    font->drawString(text,x + textOffsetX, y + textOffsetY);

  } else {

    ofSetColor(hoverFillColor);
    ofFill();
    ofDrawRectangle(rect);
    ofSetColor(hoverFontColor);
    font->drawString(text,x + textOffsetX, y + textOffsetY);

  }

}

void Button::setHoverAppearance(ofColor _hoverFillColor, ofColor _hoverFontColor) {

  hoverFillColor = _hoverFillColor;
  hoverFontColor = _hoverFontColor;

}

void Button::setFunction(Function function, int (*functionPtr)()) {

  switch (function) {
    case PushFunction:
      pushFuncPtr = functionPtr;
      pushFuncSet = true;
    break;
    case ReleaseFunction:
      releaseFuncPtr = functionPtr;
      releaseFuncSet = true;
    break;
    case HoverFunction:
      hoverFuncPtr = functionPtr;
      hoverFuncSet = true;
    break;
    default:
    break;
  }


}

int Button::hover(int _x, int _y) {
  if(_x >= x && _x <= x + w && _y >= y && _y < y + h) {
    if(hoverFuncSet)(*hoverFuncPtr)();
    hovering = true;
  } else {
    hovering = false;
  }
}

int Button::empty() {
  return 0;
}
