#pragma once
#include <string>
#include <array>

#include "p5_vector.hpp"
#include "p5_trig.hpp"

namespace P5
{

    const float e = 2.71828182845F;
    const float pi = 3.14159265359F;

    int abs(int _v);
    float abs(float _v);

    int ceil(float _v);
    int floor(float _v);

    int constrain(int _v, int _lower, int _upper);
    float constrain(float _v, float _lower, float _upper);

    // amt has to be between 0.0 and 1.0 idk why
    float lerp(float _start, float _stop, float _amt);

    float map(float _v, float _start0, float _stop0, float _start1, float _stop1);

    // same thing as map(_v, _start, _stop, 0, 1) but ok
    float norm(float _v, float _start, float _stop);

    int max(int _a, int _b);
    float max(float _a, float _b);

    int min(int _a, int _b);
    float min(float _a, float _b);

    int round(float _v);

    float dist(float _x0, float _y0, float _x1, float _y1);
    float dist(float _x0, float _y0, float _z0, float _x1, float _y1, float _z1);

    float mag(float _x, float _y);
    float mag(float _x, float _y, float _z);

    int sq(int _v);
    float sq(float _v);
    float sqrt(float _v);
    float pow(float _base, float _ex);
    float exp(float _v);
    float log(float _v);
    float log10(float _v);

}
