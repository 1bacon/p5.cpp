#pragma once

#include <vector>

namespace p5
{
    class Math
    {
    public:
        static float sin(float _r);
        static float cos(float _r);
        static float tan(float _r);
        static float asin(float _r);
        static float acos(float _r);
        static float atan(float _r);
        static float atan2(float _y, float _x);
        static float degrees(float _r);
        static float radians(float _r);

        static int abs(int _v);
        static float abs(float _v);

        static int ceil(float _v);
        static int floor(float _v);

        static int constrain(int _v, int _lower, int _upper);
        static float constrain(float _v, float _lower, float _upper);

        // amt has to be between 0.0 and 1.0 idk why
        static float lerp(float _start, float _stop, float _amt);

        static float map(float _v, float _start0, float _stop0, float _start1, float _stop1);

        // same thing as map(_v, _start, _stop, 0, 1) but ok
        static float norm(float _v, float _start, float _stop);

        static float max(float a, float b);
        static float max(float a, float b, float c);
        static float max(std::vector<float> list);

        static int max(int a, int b);
        static int max(int a, int b, int c);
        static int max(std::vector<int> list);

        static float min(float a, float b);
        static float min(float a, float b, float c);
        static float min(std::vector<float> list);

        static int min(int a, int b);
        static int min(int a, int b, int c);
        static int min(std::vector<int> list);

        static int round(float _v);

        static float dist(float _x0, float _y0, float _x1, float _y1);
        static float dist(float _x0, float _y0, float _z0, float _x1, float _y1, float _z1);

        static float mag(float _x, float _y);
        static float mag(float _x, float _y, float _z);

        static int sq(int _v);
        static float sq(float _v);
        static float sqrt(float _v);
        static float pow(float _base, float _ex);
        static float exp(float _v);
        static float log(float _v);
        static float log10(float _v);
    };
}
