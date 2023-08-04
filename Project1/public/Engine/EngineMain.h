#pragma once
#define SDL_MAIN_HANDLED
#include <memory>
#include <iostream>
#include <SDL.h>

class EngineMain
{

public:

	EngineMain();

	~EngineMain();

	void init(const char* title, const int xpos, const int ypos, const int height, const int with, const bool bfullscreen);

	void handleEvents();

	void Tick();

	void Render();

	void clear();

	bool running();

private:

	int count = 0;
	
	bool bIsRunning;

	SDL_Window* MainWindow;
	SDL_Renderer* Renderer;


};

