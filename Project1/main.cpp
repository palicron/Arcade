#pragma once
#define SDL_MAIN_HANDLED
#include <memory>
#include <iostream>
#include <SDL.h>

#include "EngineMain.h"

int main(int argc, char* argv[])
{
	//Create the Engine Class as a Smart Pointer 
	std::unique_ptr<EngineMain> Engine(new EngineMain());


	
	

	SDL_Init(SDL_INIT_EVENTS);
	SDL_Window* mainWindow = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);
	SDL_Renderer* Renderer = SDL_CreateRenderer(mainWindow, -1, 0);

	SDL_SetRenderDrawColor(Renderer,0,255,0,255);

	SDL_RenderClear(Renderer);

	SDL_RenderPresent(Renderer);

	SDL_Delay(300);

	return 0;
}