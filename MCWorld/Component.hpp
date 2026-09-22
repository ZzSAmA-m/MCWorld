#pragma once
#include <memory>
class GameObj;
class Component
{
protected:
	GameObj* _gameobj=nullptr;		
public:
	virtual GameObj* GetGameObj() { return this->_gameobj; }
	virtual void Update(){}
	virtual void Start() {}

};

