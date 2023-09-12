#pragma once

#include "../EngineMain.h"

class GameObject
{
public:
    GameObject(const char* textureSheet, SDL_Renderer* RendererRef, int initxpos, int initypos );
    
    ~GameObject();

    virtual void Update();

    virtual void Render();
    
protected:

    //TODO MAKE TRAFORMS
    int Xpos;
    int Ypos;

    SDL_Texture* ObjectTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer* Renderer;
    
};
