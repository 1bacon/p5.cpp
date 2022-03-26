#pragma once
#include <cmath>

namespace P5{
    // TODO: Implement the P5 degrees / radians with Applet state
    using std::acos;
    using std::asin;
    using std::atan2;
    using std::atan;
    using std::cos;
    using std::sin;
    using std::tan;

    float degrees(float _radians);
    float radians(float _degrees);
}