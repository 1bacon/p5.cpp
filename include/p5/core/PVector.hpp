#pragma once
#include <string>
#include <array>

#include "p5/core/PApplet.hpp"

namespace p5
{
    class PVector
    {
    public:
        float x, y, z;

        PVector();
        PVector(const PVector &_v);
        PVector(float x, float y);
        PVector(float x, float y, float z);
        ~PVector();

        static PVector fromAngle(float angle);
        static PVector &fromAngle(float angle, PVector target);
        static PVector random2D();
        static PVector random2D(PApplet parent);
        static PVector &random2D(PVector &target);
        static PVector &random2D(PVector &target, PApplet &parent);
        static PVector random3D();
        static PVector random3D(PApplet &parent);
        static PVector &random3D(PVector &target);
        static PVector &random3D(PVector &target, PApplet &parent);

        static PVector add(const PVector &v1, const PVector &v2);
        static PVector &add(const PVector &v1, const PVector &v2, PVector &target);
        static PVector sub(const PVector &v1, const PVector &v2);
        static PVector &sub(const PVector &v1, const PVector &v2, PVector &target);
        static PVector div(const PVector &v, float n);
        static PVector &div(const PVector &v, float n, PVector &target);
        static PVector mult(const PVector &v, float n);
        static PVector &mult(const PVector &v, float n, PVector &target);
        static PVector &cross(const PVector &v1, const PVector &v2, PVector &target);
        static float angleBetween(const PVector &v1, const PVector &v2);
        static float dot(const PVector &v1, const PVector &v2);
        static float dist(const PVector &v1, const PVector &v2);

        static PVector lerp(const PVector &v1, const PVector &v2, float amt);

        PVector add(float x, float y) const;
        PVector add(float x, float y, float z) const;
        PVector add(const PVector &v) const;
        std::array<float,3> array() const;
        PVector copy() const;
        PVector cross(const PVector &v) const;
        PVector &cross(const PVector &v, PVector &target) const;
        float dist(const PVector &v) const;
        PVector div(float n) const;
        float dot(float x, float y, float z) const;
        float dot(const PVector &v) const;
        bool equals(const PVector &other) const;
        PVector get() const;
        float *get(float target[]) const;
        int hashCode() const;
        float heading() const;
        float heading2D() const;
        PVector lerp(float x, float y, float z, float amt) const;
        PVector lerp(const PVector &v, float amt) const;
        PVector limit(float max) const;
        float mag() const;
        float magSq() const;
        PVector mult(float n) const;
        PVector normalize() const;
        PVector &normalize(PVector &target) const;
        PVector rotate(float theta) const;
        PVector &set(float source[]);
        PVector &set(float x, float y);
        PVector &set(float x, float y, float z);
        PVector &set(const PVector &v);
        PVector &setMag(float len);
        PVector &setMag(PVector &target, float len);
        PVector sub(float x, float y) const;
        PVector sub(float x, float y, float z) const;
        PVector sub(const PVector &v) const;
        std::string toString() const;

        PVector operator+(const PVector &_a) const;
        PVector operator-(const PVector &_a) const;
        PVector operator*(const PVector &_a) const;
        PVector operator*(float _scalar) const;

    private:
        /* data */
    };
}
