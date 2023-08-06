#include "../../Public/Engine/EngineMain.h"
#include <SDL_image.h>

EngineMain::EngineMain()
{
	bIsRunning = false;
}

EngineMain::~EngineMain()
{
}

void EngineMain::init(const char* title, const int xpos, const int ypos, const int height, const int with, const bool bfullscreen)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout<<"SubSystem Initialised!!!!"<<std::endl;
		MainWindow = SDL_CreateWindow(title,xpos,ypos,with,height,bfullscreen ? SDL_WINDOW_FULLSCREEN:SDL_WINDOW_RESIZABLE);
		if(MainWindow)
		{
			std::cout<<"Window Create"<<std::endl;
		}
		
		Renderer = SDL_CreateRenderer(MainWindow,-1,0);
		
		if(Renderer)
		{
			SDL_SetRenderDrawColor(Renderer,255,255,255,255);
			std::cout<<"Renderer Create"<<std::endl;
		}

		bIsRunning = true;
		
		SDL_Surface* tmpSurface = IMG_Load("../Project1/Resources/Default_Image32x32.png");
		playerTexture = SDL_CreateTextureFromSurface(Renderer, tmpSurface);
		SDL_FreeSurface(tmpSurface);
		
		return;
	}

	bIsRunning = false;

	
}

void EngineMain::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		bIsRunning = false;
		break;
	default: ;
	}
}

void EngineMain::Tick()
{
	destR.h = 32;
	destR.w = 32;
	destR.x += 1;
}

void EngineMain::Render()
{
	//Clear old Render
	SDL_RenderClear(Renderer);
	SDL_RenderCopy(Renderer,playerTexture,NULL,&destR);
	SDL_RenderPresent(Renderer);
}

void EngineMain::clear()
{
	SDL_DestroyWindow(MainWindow);
	SDL_DestroyRenderer(Renderer);
	SDL_Quit();
	std::cout<<"QUIT GAME"<<std::endl;
}

bool EngineMain::running()
{
	return bIsRunning;
}


