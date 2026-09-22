#pragma once
#include "MC.hpp"
class TestScript:public MCBehavior
{
public:
	void Start() override;
	void Update() override;
	TestScript(GameObj* owner);
	void Say();
};

