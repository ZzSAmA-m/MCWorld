#pragma once
#include "Component.hpp"
#include "Vector3.hpp"
class Transform:public Component
{
private:
	Vector3 _position;
public:
	Vector3 GetPosition(); 
	void SetPosition(Vector3 newPos);


	Transform(GameObj* owner);
};

