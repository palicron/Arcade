#pragma once
#define SDL_MAIN_HANDLED
#include <memory>
#include <iostream>
#include <SDL.h>

class TileMap;
class GameObject;
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

	static SDL_Renderer* Renderer ;

	TileMap* Map;
private:
	
	bool bIsRunning;
	
	GameObject* Player;
	
	SDL_Window* MainWindow;
	


};

