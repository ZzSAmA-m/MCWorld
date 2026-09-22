#pragma once
#include <unordered_map>
#include <memory>
#include <string>
class GameObj;
class World
{
private:
	std::unordered_map<__int64, std::shared_ptr<GameObj>> _gameobjs;
	unsigned __int64 _curId=0;
	unsigned __int64 _loopTime = 0;
	float _loopDeltaTime = 0.5f;

	void MainLoop(unsigned __int64 times);
	void GameInit();
public:
	std::shared_ptr<GameObj> AddGameObj();
	std::shared_ptr<GameObj> AddGameObj(std::string& name);
	std::shared_ptr<GameObj> AddGameObj(std::string&& name);

	void StartLoop(unsigned __int64 times);
	void SetLoopDeltaTime(float val);
	void UpdateWorld();
};

