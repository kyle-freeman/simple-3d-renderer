#pragma once
#include "Vector3.h"

class Matrix4 {
public:
    float m[4][4];

    Matrix4();
    Matrix4(float diagonal);
    
    static Matrix4 identity();
    static Matrix4 translation(const Vector3& t);
    static Matrix4 rotation(float angle, const Vector3& axis);
    static Matrix4 scale(const Vector3& s);
    static Matrix4 perspective(float fov, float aspect, float near, float far);
    static Matrix4 lookAt(const Vector3& eye, const Vector3& center, const Vector3& up);
    
    Matrix4 operator*(const Matrix4& other) const;
    Vector3 operator*(const Vector3& v) const;
    
    Matrix4 transpose() const;
    Matrix4 inverse() const;
    
    float& operator()(int row, int col);
    const float& operator()(int row, int col) const;
};
