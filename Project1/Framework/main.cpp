#pragma once
#define SDL_MAIN_HANDLED
#include <memory>
#include <iostream>
#include <SDL.h>

#include "../Public/Engine/EngineMain.h"

//Global pointer to engine
std::unique_ptr<EngineMain> Engine(new EngineMain());

int main(int argc, char* argv[])
{
	//Create the Engine Class as a Smart Pointer 

	Engine->init("Arcade",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,false);
	
	while(Engine->running())
	{
		Engine->handleEvents();
		Engine->Tick();
		Engine->Render();
	}
	Engine->clear();

	return 0;
}