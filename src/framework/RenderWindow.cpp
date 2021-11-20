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
    this->title = p_title;
    this->width = p_w;
    this->height = p_h;
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
        flip = (SDL_RendererFlip)(SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);
    }else if(entity->flipVertical()) {
        flip = (SDL_RendererFlip)SDL_FLIP_VERTICAL;
    }else if(entity->flipHorizontal()) {
        flip = (SDL_RendererFlip)SDL_FLIP_HORIZONTAL;
    }

    SDL_RenderCopyEx(renderer, entity->getTexture(), &src, &dst, 0, 0, flip);
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}

void RenderWindow::init() {
    window = SDL_CreateWindow(this->title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->width, this->height, SDL_WINDOW_SHOWN);

    if (window == nullptr)
    {
        std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

int RenderWindow::getWidth() const {
    return width;
}

void RenderWindow::setWidth(int width) {
    RenderWindow::width = width;
}

int RenderWindow::getHeight() const {
    return height;
}

void RenderWindow::setHeight(int height) {
    RenderWindow::height = height;
}

const char *RenderWindow::getTitle() const {
    return title;
}

void RenderWindow::setTitle(const char *title) {
    RenderWindow::title = title;
}
