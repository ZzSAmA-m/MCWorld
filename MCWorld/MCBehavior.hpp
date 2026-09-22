#pragma once
#include "Component.hpp"
class MCBehavior:public Component
{
public:
	virtual void Start() = 0;
	virtual void Update() = 0;
};

