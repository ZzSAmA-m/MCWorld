#include "World.hpp"
#include "MC.hpp"
#include <thread>
#include <chrono>
void World::MainLoop(unsigned __int64 times)
{
	GameInit();
	for (unsigned __int64 i = 0; i < times; ++i) {
		UpdateWorld();
		std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(this->_loopDeltaTime*1000)));
	}
}
void World::GameInit()
{
	for (const auto& go : _gameobjs) {
		for (const auto& behavior : go.second->_behaviors) {
			behavior.second->Start();
		}
	}
}
std::shared_ptr<GameObj> World::AddGameObj()
{
	return AddGameObj("GameObj");
}

std::shared_ptr<GameObj> World::AddGameObj(std::string& name)
{
	return AddGameObj(std::move(name));
}

std::shared_ptr<GameObj> World::AddGameObj(std::string&& name)
{
	auto GO = std::make_shared<GameObj>(++_curId,name);
	_gameobjs[_curId] = GO;
	return GO;
}

void World::StartLoop(unsigned __int64 times)
{
	std::thread Tmainloop(&World::MainLoop,this,times);
	Tmainloop.join();
}

void World::SetLoopDeltaTime(float val)
{
	if (val <= 0) throw std::logic_error("间隔时间不可以小于0!");
	_loopDeltaTime = val;
}

void World::UpdateWorld()
{
	for (const auto& go : _gameobjs) {
		for (const auto& behavior : go.second->_behaviors) {
			behavior.second->Update();
		}
	}
}
