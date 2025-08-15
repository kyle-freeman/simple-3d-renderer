#include <iostream>
#include <array>
#include <cmath>

class Matrix4 {
public:
    std::array<std::array<float, 4>, 4> m;

    // Constructors
    Matrix4() {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                m[i][j] = (i == j) ? 1 : 0; // Identity matrix
    }

    Matrix4(const std::array<std::array<float, 4>, 4>& values) : m(values) {}

    // Matrix operations
    Matrix4 operator+(const Matrix4& other) const {
        Matrix4 result;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                result.m[i][j] = m[i][j] + other.m[i][j];
        return result;
    }

    Matrix4 operator-(const Matrix4& other) const {
        Matrix4 result;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                result.m[i][j] = m[i][j] - other.m[i][j];
        return result;
    }

    Matrix4 operator*(const Matrix4& other) const {
        Matrix4 result;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                result.m[i][j] = m[i][0] * other.m[0][j] + m[i][1] * other.m[1][j] + 
                                  m[i][2] * other.m[2][j] + m[i][3] * other.m[3][j];
        return result;
    }

    float determinant() const {
        // Calculate the determinant of the matrix (4x4 matrix)
        // Implementation can be added here
        return 0; // Placeholder
    }

    // Transformations
    static Matrix4 translation(float tx, float ty, float tz) {
        Matrix4 result;
        result.m[0][3] = tx;
        result.m[1][3] = ty;
        result.m[2][3] = tz;
        return result;
    }

    static Matrix4 rotation(float angle, float x, float y, float z) {
        Matrix4 result;
        // Implementation for rotation matrix
        return result; // Placeholder
    }

    static Matrix4 scaling(float sx, float sy, float sz) {
        Matrix4 result;
        result.m[0][0] = sx;
        result.m[1][1] = sy;
        result.m[2][2] = sz;
        return result;
    }

    // Utility functions
    Matrix4 transpose() const {
        Matrix4 result;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                result.m[j][i] = m[i][j];
        return result;
    }

    Matrix4 inverse() const {
        // Implementation for matrix inversion
        return *this; // Placeholder
    }
};
