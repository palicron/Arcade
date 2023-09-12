#include "../../../Public/Engine/Object/GameObject.h"
#include "../../../Public/Engine/TextureManager.h"

GameObject::GameObject(const char* textureSheet, SDL_Renderer* RendererRef, int initxpos, int initypos): Xpos(initxpos), Ypos(initypos), srcRect(), destRect()
{
    Renderer = RendererRef;
    ObjectTexture = TextureManager::load_texture(textureSheet, Renderer);
}

GameObject::~GameObject()
{
    SDL_DestroyTexture(ObjectTexture);
    Renderer = nullptr;
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
    SDL_RenderCopy(Renderer,ObjectTexture,NULL,&destRect);
}
