#pragma once

#include "../EngineMain.h"

class GameObject
{
public:
    GameObject(const char* textureSheet, int initxpos, int initypos );
    
    ~GameObject();

    virtual void Update();

    virtual void Render();
    
protected:

    //TODO MAKE TRAFORMS
    int Xpos;
    int Ypos;

    SDL_Texture* ObjectTexture;
    SDL_Rect srcRect, destRect;
    
};
