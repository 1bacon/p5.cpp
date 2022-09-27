#include "p5/core/PVector.hpp"

#include <sstream>

#include "p5/core/Math.hpp"

namespace p5
{
    PVector::PVector()
    {
        PVector(0, 0, 0);
    }
    PVector::PVector(const PVector &_v)
    {
        PVector(_v.x, _v.y, _v.z);
    }
    PVector::PVector(float x, float y)
    {
        PVector(x, y, 0);
    }
    PVector::PVector(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    PVector::~PVector() {}

    //
    // STATIC
    //

    PVector PVector::add(const PVector &v1, const PVector &v2)
    {
        return PVector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
    }
    PVector &PVector::add(const PVector &v1, const PVector &v2, PVector &_target)
    {
        _target.set(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
        return _target;
    }
    PVector PVector::sub(const PVector &v1, const PVector &v2)
    {
        return PVector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
    }
    PVector &PVector::sub(const PVector &v1, const PVector &v2, PVector &target)
    {
        target.set(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
        return target;
    }
    PVector PVector::div(const PVector &v, float n)
    {
        return PVector::mult(v, 1 / n);
    }
    PVector &PVector::div(const PVector &v, float n, PVector &target)
    {
        target.set(v.x / n, v.y / n, v.z / n);
        return target;
    }
    PVector PVector::mult(const PVector &v, float n)
    {
        return PVector(v.x * n, v.y * n, v.z * n);
    }
    PVector &PVector::mult(const PVector &v, float n, PVector &target)
    {
        target.set(v.x * n, v.y * n, v.z * n);
        return target;
    }
    PVector &PVector::cross(const PVector &v1, const PVector &v2, PVector &target)
    {
        target.set(
            v1.y * v2.z - v1.z * v2.y,
            v1.z * v2.x - v1.x * v2.z,
            v1.x * v2.y - v1.y * v2.x);
        return target;
    }
    float angleBetween(const PVector &v1, const PVector &v2)
    {
        return Math::acos(Math::constrain(PVector::dot(v1, v2) / v1.mag() * v2.mag(), -1.0, 1.0));
    }
    float PVector::dot(const PVector &v1, const PVector &v2)
    {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    }
    float PVector::dist(const PVector &v1, const PVector &v2)
    {
        return sub(v1, v2).mag();
    }

    PVector PVector::lerp(const PVector &v1, const PVector &v2, float amt)
    {
        return PVector(
            Math::lerp(v1.x, v2.x, amt),
            Math::lerp(v1.y, v2.y, amt),
            Math::lerp(v1.z, v2.z, amt));
    }

    //
    // INSTANCE
    //

    PVector PVector::add(float x, float y, float z) const
    {
        return PVector::add(*this, PVector(x, y, z));
    }

    PVector PVector::add(float x, float y) const
    {
        return PVector::add(*this, PVector(x, y));
    }

    PVector PVector::add(const PVector &v) const
    {
        return PVector::add(*this, v);
    }

    std::array<float, 3> PVector::array() const
    {
        return std::array<float, 3>{this->x,this->y,this->z};
    }

    PVector PVector::copy() const
    {
        return PVector(*this);
    }

    PVector PVector::cross(const PVector &v) const
    {
        PVector result;
        PVector::cross(*this, v, result);
        return result;
    }

    PVector &PVector::cross(const PVector &v, PVector &target) const
    {
        return PVector::cross(*this, v, target);
    }

    float PVector::dist(const PVector &v) const
    {
        return PVector::dist(*this, v);
    }

    PVector PVector::div(float n) const
    {
        return PVector::div(*this, n);
    }

    float PVector::dot(float x, float y, float z) const
    {
        return PVector::dot(*this, PVector(x, y, z));
    }

    float PVector::dot(const PVector &v) const
    {
        return PVector::dot(*this, v);
    }

    bool PVector::equals(const PVector &other) const
    {
        return this == &other;
    }

    PVector PVector::get() const
    {
        return copy();
    }

    float *PVector::get(float target[]) const
    {
        target[0] = this->x;
        target[1] = this->y;
        target[2] = this->z;
        return target;
    }

    int PVector::hashCode() const
    {
        return 69;
    }

    float PVector::heading() const
    {
        return PVector::angleBetween(*this, PVector());
    }

    PVector PVector::lerp(float x, float y, float z, float amt) const
    {
        return PVector::lerp(*this, PVector(x, y, z), amt);
    }

    PVector PVector::lerp(const PVector &v, float amt) const
    {
        return PVector::lerp(*this, v, amt);
    }

    PVector PVector::limit(float max) const
    {
        if (mag() > max)
        {
            return copy().setMag(max);
        }
        return copy();
    }

    PVector PVector::mult(float n) const
    {
        return PVector::mult(*this, n);
    }

    PVector PVector::normalize() const
    {
        return copy().setMag(1.0);
    }

    //https://matthew-brett.github.io/teaching/rotation_2d.html
    PVector PVector::rotate(float theta) const
    {
        return PVector(
            Math::cos(theta) * this->x - Math::sin(theta) * this->y,
            Math::sin(theta) * this->x + Math::cos(theta) * this->y
        );
    }

    PVector &PVector::normalize(PVector &target) const
    {
        return target.set(*this).setMag(1.0);
    }

    PVector &PVector::setMag(float len)
    {
        return PVector::mult(*this, len / mag(), *this);
    }

    PVector &PVector::setMag(PVector &target, float len)
    {
        return PVector::mult(*this, len / mag(), target);
    }

    PVector PVector::sub(float x, float y) const
    {
        return PVector::sub(*this, PVector(x, y));
    }

    PVector PVector::sub(float x, float y, float z) const
    {
        return PVector::sub(*this, PVector(x, y, z));
    }

    PVector PVector::sub(const PVector &v) const
    {
        return PVector::sub(*this, v);
    }

    PVector PVector::operator+(const PVector &_a) const
    {
        return PVector::add(*this, _a);
    }

    PVector PVector::operator-(const PVector &_a) const
    {
        return PVector::sub(*this, _a);
    }

    PVector PVector::operator*(const PVector &_a) const
    {
        return this->cross(_a);
    }

    PVector PVector::operator*(float _scalar) const
    {
        return PVector::mult(*this, _scalar);
    }

    PVector &PVector::set(float source[])
    {
        return this->PVector::set(source[0], source[1], source[2]);
    }
    PVector &PVector::set(float x, float y)
    {
        return this->set(x, y, 0);
    }
    PVector &PVector::set(const PVector &v)
    {
        return this->set(v.x, v.y, v.z);
    }
    PVector &PVector::set(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        return *this;
    }

    float PVector::mag() const
    {
        return Math::sqrt(magSq());
    }
    float PVector::magSq() const
    {
        return Math::sq(x) + Math::sq(y) + Math::sq(z);
    }

    std::string PVector::toString() const
    {
        return (std::stringstream() << "(" << this->x << ", " << this->y << ", " << this->z << ")").str();
    }
}