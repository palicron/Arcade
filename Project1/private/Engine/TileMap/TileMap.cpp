#include "../../../Public/Engine/TileMap/TileMap.h"
#include "../../../Public/Engine/TextureManager.h"

int lvl1[20][25] ={
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,2,0,2,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};
TileMap::TileMap()
{
    dirt = TextureManager::load_texture(RESOURCESTEXTURES("Dirt.png"));
    grass = TextureManager::load_texture(RESOURCESTEXTURES("grass.png"));
    water = TextureManager::load_texture(RESOURCESTEXTURES("water.jpg"));

    LoadMap(lvl1);
    src.x = src.y = 0;
    src.h = src.w = dest.w = dest.h = 32;
    dest.x = dest.y = 0;
}

void TileMap::LoadMap(const int mapFile[20][25])
{
    for (int row = 0; row < 20 ; row ++)
    {
        for(int col = 0; col < 25 ; col ++)
        {
            map[row][col] = mapFile[row][col];
        }
    }
}

void TileMap::DrawMap()
{

    for (int row = 0; row < 20 ; row ++)
    {
        for(int col = 0; col < 25 ; col ++)
        {
         
            dest.x = col * dest.w;
            dest.y = row * dest.h;
            
            switch (map[row][col])
            {
            case 0:
                TextureManager::DrawTexture(grass,src,dest);
                break;
            case 1:
                TextureManager::DrawTexture(dirt,src,dest);
                break;
            case 2:
                TextureManager::DrawTexture(water,src,dest);
                break;
            default: ;
            }
        }
    }
}

