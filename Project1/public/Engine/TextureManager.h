#pragma once
#include <SDL_rect.h>


struct SDL_Texture;
struct SDL_Renderer;

class TextureManager
{
    
public:
    static SDL_Texture* load_texture(const char* fileName);

    static void DrawTexture(SDL_Texture* InTexture, SDL_Rect src, SDL_Rect destination);
};
