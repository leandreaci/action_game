//
// Created by leandro on 21/04/2020.
//
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.h"
#include "Entity.h"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

    if (window == nullptr)
    {
        std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
    SDL_Texture* texture = nullptr;
    texture = IMG_LoadTexture(renderer, p_filePath);

    if (texture == nullptr)
        std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

    return texture;
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(window);
}

void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity* entity)
{
    SDL_Rect src;
    src.x = entity->getCurrentFrame().x;
    src.y = entity->getCurrentFrame().y;
    src.w = entity->getCurrentFrame().w;
    src.h = entity->getCurrentFrame().h;

    SDL_Rect dst;
    dst.x = entity->getX();
    dst.y = entity->getY();
    dst.w = entity->getCurrentFrame().w * 4;
    dst.h = entity->getCurrentFrame().h * 4;

    SDL_RendererFlip flip = (SDL_RendererFlip)SDL_FLIP_NONE;
    if(entity->flipHorizontalVertical()) {
        std::cout << "flipHorizontalVertical" << std::endl;
        flip = (SDL_RendererFlip)(SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL); 
    }else if(entity->flipVertical()) {
        std::cout << "flipVertical" << std::endl;
        flip = (SDL_RendererFlip)SDL_FLIP_VERTICAL; 
    }else if(entity->flipHorizontal()) {
        std::cout << "flipHorizontal" << std::endl;
        flip = (SDL_RendererFlip)SDL_FLIP_HORIZONTAL;
    }

    SDL_RenderCopyEx(renderer, entity->getTexture(), &src, &dst, 0, 0, flip);
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}