#pragma once
#include <SDL_rect.h>
#include <SDL_render.h>


class TileMap
{
public:

    TileMap();

    ~TileMap()=default;

    void LoadMap();
    void DrawMap();
private:

    SDL_Rect src,dest;
    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;

    int map[20][25];
    
};
