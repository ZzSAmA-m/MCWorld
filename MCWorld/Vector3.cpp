#include "Vector3.hpp"
#include <math.h>

Vector3::Vector3():Vector3(0,0,0)
{
}

Vector3::Vector3(float x, float y, float z):x(x),y(y),z(z)
{
}

Vector3 Vector3::Normalize()
{
	float m = sqrt(x * x + y * y + z * z);
	return Vector3{x/m,y/m,z/m};
}

Vector3 Vector3::operator+(const Vector3& other) const {
	return Vector3{ x + other.x,y + other.y,z + other.z };
}

Vector3 Vector3::operator-(const Vector3& other) const
{
	return Vector3{ x - other.x,y - other.y,z - other.z };
}

Vector3 Vector3::operator*(const Vector3& other) const
{
	return Vector3{ x * other.x,y * other.y,z * other.z };
}

Vector3 Vector3::operator/(const Vector3& other) const
{
	return Vector3{ x / other.x,y / other.y,z / other.z };
}
