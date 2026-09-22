#include "MC.hpp"
#include "TestScript.hpp"
#include <iostream>
int main() {
	auto wd = new World();
	auto go=wd->AddGameObj("zz");
	go->AddComponent<TestScript>();
	wd->SetLoopDeltaTime(0.5f);
	wd->StartLoop(5);
	delete wd;
}