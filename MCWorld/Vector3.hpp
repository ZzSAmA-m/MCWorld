#pragma once
struct Vector3
{
public:
	float x, y, z;
	Vector3();
	Vector3(float x, float y, float z);
	/// <summary>
	/// 向量归一化,返回归一化后的向量
	/// </summary>
	/// <returns></returns>
	Vector3 Normalize();
	

	//重载操作符
	Vector3 operator+(const Vector3& other) const;

	Vector3 operator-(const Vector3& other) const;

	Vector3 operator*(const Vector3& other) const;

	Vector3 operator/(const Vector3& other) const;


};

