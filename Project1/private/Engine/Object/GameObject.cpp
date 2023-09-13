#include "../../../Public/Engine/Object/GameObject.h"
#include "../../../Public/Engine/TextureManager.h"

GameObject::GameObject(const char* textureSheet, int initxpos, int initypos): Xpos(initxpos), Ypos(initypos), srcRect(), destRect()
{
    ObjectTexture = TextureManager::load_texture(textureSheet);
}

GameObject::~GameObject()
{
    SDL_DestroyTexture(ObjectTexture);
    
}

void GameObject::Update()
{
    Xpos ++;
    Ypos ++;

    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = Xpos;
    destRect.y = Ypos;
    destRect.w = srcRect.w * 2;
    destRect.h =  srcRect.h * 2;
}

void GameObject::Render()
{
    SDL_RenderCopy(EngineMain::Renderer,ObjectTexture,NULL,&destRect);
}
