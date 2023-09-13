#pragma once


struct SDL_Texture;
struct SDL_Renderer;

class TextureManager
{
    
public:
    static SDL_Texture* load_texture(const char* fileName);
};
