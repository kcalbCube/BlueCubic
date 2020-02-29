#include "vector.h"

Vector Vector::operator+(const Vector& vector) const
{
	return { x + vector.x, y + vector.y };
}

Vector& Vector::operator+=(const Vector& vector)
{
	x += vector.x;
	y += vector.y;

	return *this;
}

Vector Vector::operator-(const Vector& vector) const
{
	return { x - vector.x, y - vector.y };
}

Vector& Vector::operator-=(const Vector& vector)
{
	x -= vector.x;
	y -= vector.y;

	return *this;
}

Vector Vector::operator*(double scalar) const
{
	return { x * scalar, y * scalar };
}

Vector& Vector::operator*=(double scalar)
{
	x *= scalar;
	y *= scalar;

	return *this;
}

double Vector::length(void) const
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

double Vector::length(Vector vector) const
{
	return Vector(*this - vector).length();
}

bool Vector::isNormalized(void) const
{
	double len = length();

	return len > 0.99 && len < 1.01;
}

Vector& Vector::normalize(void)
{
	if (isNormalized())
		return *this;

	double len = length();

	x /= len;
	y /= len;

	return *this;
}