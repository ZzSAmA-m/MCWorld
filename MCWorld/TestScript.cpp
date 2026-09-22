#include "TestScript.hpp"
#include <print>
void TestScript::Start()
{
	std::println("Inited!");
}
void TestScript::Update()
{
	Say();
}
TestScript::TestScript(GameObj* owner)
{
	this->_gameobj = owner;
}

void TestScript::Say()
{
	std::println("hello!");
}
