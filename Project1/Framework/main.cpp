#pragma once
#define SDL_MAIN_HANDLED
#include <memory>
#include <iostream>
#include <SDL.h>

#include "../Public/Engine/EngineMain.h"


//Global pointer to engine
std::unique_ptr<EngineMain> Engine(new EngineMain());

constexpr int FPS = 60;
constexpr int FRAME_DELAY = 1000/FPS;
Uint32 LastFrameTime = 0;


int main(int argc, char* argv[])
{
	//Create the Engine Class as a Smart Pointer 
	Uint32 frameStart = 0;
	Uint32 frameTime = 0;
	
	Engine->init("Arcade",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,false);
	
	while(Engine->running())
	{
		frameStart = SDL_GetTicks();
		
		Engine->handleEvents();
		Engine->Tick();
		Engine->Render();

		frameTime = SDL_GetTicks()-frameStart;
		LastFrameTime = frameTime;
		std::cout<<FRAME_DELAY<<std::endl;
		
		if(FRAME_DELAY > frameTime )
		{
			SDL_Delay(FRAME_DELAY-frameTime);
		}
	}
	Engine->clear();

	return 0;
}