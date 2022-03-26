#include "p5_math/vector.hpp"
#include "p5_math/math.hpp"
#include <string>
#include <array>
#include <sstream>
#include <stdexcept>

namespace P5
{

    PVector::PVector()
    {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }
    PVector::PVector(float _x, float _y)
    {
        this->x = _x;
        this->y = _y;
        this->z = 0;
    }
    PVector::PVector(float _x, float _y, float _z)
    {
        this->x = _x;
        this->y = _y;
        this->z = _z;
    }

    PVector::PVector(const PVector &_v)
    {
        this->x = _v.x;
        this->y = _v.y;
        this->z = _v.z;
    }

    PVector operator+(const PVector &_a, const PVector &_b)
    {
        PVector r = {_a};
        r.x += _b.x;
        r.y += _b.y;
        r.z += _b.z;
        return r;
    }
    PVector operator-(const PVector &_a, const PVector &_b)
    {
        PVector r = {_a};
        r.x -= _b.x;
        r.y -= _b.y;
        r.z -= _b.z;
        return r;
    }
    PVector operator*(const PVector &_a, const PVector &_b)
    {
        PVector r = {_a.y * _b.z - _a.z * _b.y,
                     _a.z * _b.x - _a.x * _b.z,
                     _a.x * _b.y - _a.y * _b.x};
        return r;
    }
    PVector operator*(const PVector &_v, float _scalar)
    {
        PVector r = {_v};
        r.x *= _scalar;
        r.y *= _scalar;
        r.z *= _scalar;
        return r;
    }

    float PVector::operator[](int _i)
    {
        if (_i == 0)
            return this->x;
        if (_i == 1)
            return this->y;
        if (_i == 2)
            return this->z;
        throw std::out_of_range("Index for PVector must be between 0-3");
    }

    PVector PVector::add(const PVector &_a, const PVector &_b)
    {
        return _a + _b;
    }
    PVector PVector::add(const PVector &_v) const
    {
        return (*this) + _v;
    }

    PVector PVector::add(float _x, float _y) const
    {
        return this->add(_x, _y, 0);
    }
    PVector PVector::add(float _x, float _y, float _z) const
    {
        return this->sub(PVector{_x, _y, _z});
    }

    PVector PVector::sub(const PVector &_a, const PVector &_b)
    {
        return _a - _b;
    }
    PVector PVector::sub(const PVector &_v) const
    {
        return (*this) - _v;
    }
    PVector PVector::sub(float _x, float _y) const
    {
        return this->sub(_x, _y, 0);
    }
    PVector PVector::sub(float _x, float _y, float _z) const
    {
        return this->sub(PVector{_x, _y, _z});
    }

    PVector PVector::mult(const PVector &_v, float _scalar)
    {
        return _v.mult(_scalar);
    }
    PVector PVector::mult(float _scalar) const
    {
        return (*this) * _scalar;
    }

    PVector PVector::div(const PVector &_v, float _scalar)
    {
        return _v.div(_scalar);
    }
    PVector PVector::div(float _scalar) const
    {
        return (*this) * (1 / _scalar);
    }

    float PVector::dist(const PVector &_a, const PVector &_b)
    {
        return _a.dist(_b);
    }
    float PVector::dist(const PVector &_v) const
    {
        return (_v - *this).mag();
    }

    float PVector::dot(const PVector &_a, const PVector &_b)
    {
        return _a.dot(_b);
    }
    float PVector::dot(const PVector &_v) const
    {
        return this->x*_v.x + this->y*_v.y + this->z*_v.z;
    }

    PVector PVector::cross(const PVector &_a, const PVector &_b)
    {
        return _a.cross(_b);
    }
    PVector PVector::cross(const PVector &_v) const
    {
        return (*this) * _v;
    }

    PVector PVector::normalize(const PVector &_v)
    {
        return _v.normalize();
    }
    PVector PVector::normalize() const 
    {
        PVector p = {*this};
        float m = p.mag();
        p.x /= m;
        p.y /= m;
        p.z /= m;
        return p;
    }

    PVector PVector::limit(float _max) const 
    {
        PVector p = {*this};
        float m = p.mag();
        if (m > _max)
            return p.setMag(_max);
        return p;
    }

    PVector PVector::setMag(const PVector &_v, float _len)
    {
        return _v.setMag(_len);
    }
    PVector PVector::setMag(float _len) const
    {
        PVector p = {*this};
        return p.normalize() * _len;
    }

    PVector PVector::rotate(float _theta) const
    {
        PVector p = fromAngle(_theta);
        p.setMag(this->mag());
        return p;
    }
    float PVector::heading() const
    {
        return atan2(this->y, this->x);
    }

    PVector PVector::lerp(const PVector &_a, const PVector &_b, float _amt)
    {
        return _a.lerp(_b, _amt);
    }
    PVector PVector::lerp(float _x, float _y, float _z, float _amt) const
    {
        return this->lerp(PVector{_x, _y, _z}, _amt);
    }
    PVector PVector::lerp(const PVector &_v, float _amt) const 
    {
        PVector p;
        p.x = P5::lerp(this->x,_v.x,_amt);
        p.y = P5::lerp(this->y,_v.y,_amt);
        p.z = P5::lerp(this->z,_v.z,_amt);
        return p;
    }

    float PVector::angleBetween(const PVector &_a, const PVector &_b)
    {
        return P5::acos(P5::constrain(_a.dot(_b) / _a.mag() * _b. mag(),-1.0,1.0));
    }

    std::array<float, 3> PVector::array() const
    {
        return std::array<float, 3> {this->x, this->y, this->z};
    }

    float PVector::mag() const
    {
        return P5::sqrt(this->magSq());
    }
    float PVector::magSq() const
    {
        return P5::sq(this->x) + P5::sq(this->y) + P5::sq(this->z);
    }
    PVector PVector::copy() const
    {
        return PVector{*this};
    }

    //PVector PVector::random2D();
    //PVector PVector::random3D();
    PVector PVector::fromAngle(float _angle)
    {
        PVector p;
        p.x = cos(_angle);
        p.y = sin(_angle);
        p.z = 0;
        return p;
    }

    // (x, y, z)
    std::string PVector::toString() const
    {
        std::ostringstream outst;
        outst << "(" << this->x << ", " << this->y << ", " << this->z << ")";
        return outst.str();
    }

}