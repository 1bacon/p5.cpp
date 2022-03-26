#include "p5_math/trig.hpp"
#include "p5_math/math.hpp"

namespace P5{

    float degrees(float _radians)
    {
        return _radians * 180/pi;
    }
    float radians(float _degrees)
    {
        return _degrees * pi/180;
    }

}