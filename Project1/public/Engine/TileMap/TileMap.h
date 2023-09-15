#pragma once
#include <SDL_rect.h>
#include <SDL_render.h>
#
#define RESOURCESTEXTURES(File_Name) ("../Project1/Resources/TileTexture/" ## File_Name)

class TileMap
{
public:

    TileMap();

    ~TileMap()=default;

    void LoadMap(const int mapFile[20][25]);
    void DrawMap();
private:

    SDL_Rect src,dest;
    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;

    int map[20][25];
    
};
