#include "../../Public/Engine/TextureManager.h"

#include <iostream>
#include <SDL_image.h>
#include <SDL_render.h>

SDL_Texture* TextureManager::load_texture(const char* fileName,SDL_Renderer* Renderer)
{
    SDL_Surface* TempSurface = IMG_Load(fileName);
    if(TempSurface)
    {
        SDL_Texture* Texture = SDL_CreateTextureFromSurface(Renderer,TempSurface);
        SDL_FreeSurface(TempSurface);
        return Texture;
    }
    
    SDL_FreeSurface(TempSurface);
    std::cout<<"File not load to surface path, no file found"<<std::endl;
    return nullptr;
}
