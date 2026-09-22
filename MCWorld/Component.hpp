#pragma once
#include <memory>
class GameObj;
class Component
{
protected:
	/// <summary>
	/// 持有此组件的GameObj
	/// </summary>
	GameObj* _gameobj=nullptr;		
public:
	/// <summary>
	/// 返回持有此组件的GameObj
	/// </summary>
	/// <returns></returns>
	virtual GameObj* GetGameObj() { return this->_gameobj; }
};

