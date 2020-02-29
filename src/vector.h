#pragma once

#include <cmath>

class Vector
{
public:

	double x = 0.0, y = 0.0;

	double length(void) const;

	double length(Vector vector) const;

	bool isNormalized(void) const;

	Vector& normalize(void);

	Vector operator+(const Vector& vector) const;

	Vector& operator+=(const Vector& vector);

	Vector operator-(const Vector& vector) const;

	Vector& operator-=(const Vector& vector);

	Vector operator*(double scalar) const;

	Vector& operator*=(double scalar);
};