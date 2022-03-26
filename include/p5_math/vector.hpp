#pragma once
#include <array>
#include <string>


namespace P5
{

    class PVector
    {
    public:
        PVector();
        PVector(float _x, float _y);
        PVector(float _x, float _y, float _z);
        PVector(const PVector &_v);

        float x, y, z;

        float operator[](int _i);

        PVector set(const PVector &_v);
        PVector set(float _x, float _y);
        PVector set(float _x, float _y, float _z);
        PVector set(std::array<float, 3> _source);

        static PVector add(const PVector &_a, const PVector &_b);
        PVector add(const PVector &_v) const;
        PVector add(float _x, float _y) const;
        PVector add(float _x, float _y, float _z) const;

        static PVector sub(const PVector &_a, const PVector &_b);
        PVector sub(const PVector &_v) const;
        PVector sub(float _x, float _y) const;
        PVector sub(float _x, float _y, float _z) const;

        static PVector mult(const PVector &_v, float _scalar);
        PVector mult(float _scalar) const;

        static PVector div(const PVector &_v, float _scalar);
        PVector div(float _scalar) const;

        static float dist(const PVector &_a, const PVector &_b);
        float dist(const PVector &_v) const;

        static float dot(const PVector &_a, const PVector &_b);
        float dot(const PVector &_v) const;

        static PVector cross(const PVector &_a, const PVector &_b);
        PVector cross(const PVector &_v) const;

        static PVector normalize(const PVector &_v);
        PVector normalize() const;

        PVector limit(float _max) const;

        static PVector setMag(const PVector &_v, float _len);
        PVector setMag(float _len) const;

        PVector rotate(float _theta) const;
        float heading() const;

        static PVector lerp(const PVector &_a, const PVector &_b, float _amt);
        PVector lerp(const PVector &_v, float _amt) const;
        PVector lerp(float _x, float _y, float _z, float _amt) const;

        static float angleBetween(const PVector &_a, const PVector &_b);

        std::array<float, 3> array() const;

        float mag() const;
        float magSq() const;
        PVector copy() const;

        static PVector random2D();
        static PVector random3D();
        static PVector fromAngle(float _angle);

        std::string toString() const;
    };

    PVector operator+(const PVector &_a, const PVector &_b);
    PVector operator-(const PVector &_a, const PVector &_b);
    PVector operator*(const PVector &_a, const PVector &_b);
    PVector operator*(const PVector &_a, float _scalar);

}