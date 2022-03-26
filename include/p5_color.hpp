#pragma once

// 32 bit color value #AARRGGBB
typedef int color;

//TODO implement web color e.g. '#FFCC00'

typedef char _colorMode;

_colorMode RBG = 0;
_colorMode HSV = 1;

//Creating

//FIXME: hmm... not sure what to do about this. The function should be 'color color(int _r, int _g, int _b)'
// but c++ doesn't seem to support functions with class names
color _color(int x);

//Reading
int alpha(color _c);
int blue(color _c);
int red(color _c);
int green(color _c);
int hue(color _c);
int saturation(color _c);
int brightness(color _c);

//helper
color lerpColor(color _a, color _b, float amt);

//State-Changing / Setting

void background(color _c);
void background(color _c, float _alpha);
void background(float _grey);
void background(float _v1, float _v2, float _v3); // either rbg or hsv depending on colorMode
void background(float _v1, float _v2, float _v3, float _alpha);
//TODO: add
//void background(PImage _img);

void colorMode(_colorMode _mode);
void colorMode(_colorMode _mode, float _max);
void colorMode(_colorMode _mode, float _max1, float _max2, float _max3);
void colorMode(_colorMode _mode, float _max1, float _max2, float _max3, float _maxA);

void fill(color _c);
void fill(color _c, float _alpha);
void fill(float _grey);
void fill(float _grey, float _alpha);
void fill(float _v1, float _v2, float _v3); // either rbg or hsv depending on colorMode
void fill(float _v1, float _v2, float _v3, float _alpha);

void stroke(color _c);
void stroke(color _c, float _alpha);
void stroke(float _grey);
void stroke(float _grey, float _alpha);
void stroke(float _v1, float _v2, float _v3); // either rbg or hsv depending on colorMode
void stroke(float _v1, float _v2, float _v3, float _alpha);

void noFill();
void noStroke();