#include "p5/core/Math.hpp"

#include "p5/core/Constants.hpp"

#include <cmath>

namespace p5
{

    int Math::abs(int _v)
    {
        return _v * ((_v >= 0) + ((_v < 0) * -1));
    }

    float Math::abs(float _v)
    {
        return _v * ((_v >= 0) + ((_v < 0) * -1));
    }

    int Math::ceil(float _v)
    {
        return Math::floor(_v) + 1;
    }
    int Math::floor(float _v)
    {
        return (int)_v;
    }

    int Math::max(int _a, int _b)
    {
        if (_a > _b)
            return _a;
        return _b;
    }
    float Math::max(float _a, float _b)
    {
        if (_a > _b)
            return _a;
        return _b;
    }
    
    int Math::min(int _a, int _b)
    {
        if (_a > _b)
            return _a;
        return _b;
    }
    float Math::min(float _a, float _b)
    {
        if (_a > _b)
            return _a;
        return _b;
    }

    int Math::round(float _v)
    {
        if ((int)(_v * 10) % 10 < 5)
        {
            return floor(_v);
        }
        return ceil(_v);
    }
    int Math::constrain(int _v, int _lower, int _upper)
    {
        if (_v > _upper)
            return _upper;
        if (_v < _lower)
            return _lower;
        return _v;
    }
    float Math::constrain(float _v, float _lower, float _upper)
    {
        if (_v > _upper)
            return _upper;
        if (_v < _lower)
            return _lower;
        return _v;
    }

    // amt should to be between 0.0 and 1.0
    float Math::lerp(float _start, float _stop, float _amt)
    {
        return _start + (_stop - _start) * _amt;
    }

    // https://stackoverflow.com/a/5735770
    float Math::map(float _v, float _start0, float _stop0, float _start1, float _stop1)
    {
        return (_v - _start0) * (_stop1 - _start1) / (_stop0 - _start0) + _start1;
    }

    // same thing as map(_v, _start, _stop, 0, 1) but ok
    float Math::norm(float _v, float _start, float _stop)
    {
        return map(_v, _start, _stop, 0, 1);
    }

    float Math::dist(float _x0, float _y0, float _x1, float _y1)
    {
        return dist(_x0, _y0, 0, _x1, _y1, 0);
    }
    float Math::dist(float _x0, float _y0, float _z0, float _x1, float _y1, float _z1)
    {
        return sqrt(sq(_x1 - _x0) + sq(_y1 - _y0) + sq(_z1 - _z0));
    }

    int Math::sq(int _v)
    {
        return _v * _v;
    }
    float Math::sq(float _v)
    {
        return _v * _v;
    }
    float Math::sqrt(float _v)
    {
        return std::sqrt(_v);
    }
    float Math::pow(float _base, float _ex)
    {
        return std::pow(_base, _ex);
    }
    float Math::exp(float _v)
    {
        return pow(Constants::E, _v);
    }
    float Math::log(float _v)
    {
        return std::log(_v);
    }
    float Math::log10(float _v)
    {
        return std::log10(_v);
    }

} // namespace p5
