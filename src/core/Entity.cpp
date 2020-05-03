//
// Created by leandro on 21/04/2020.
//

#include "Entity.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Entity::Entity(float p_x, float p_y, SDL_Texture* p_tex)
{
    this->x = p_x;
    this->y = p_y;
    this->texture = p_tex;
}

float Entity::getX()
{
    return x;
}
float Entity::getY()
{
    return y;
}

SDL_Texture* Entity::getTexture()
{
    return texture;
}

SDL_Rect Entity::getCurrentFrame()
{
    return currentFrame;
}

void Entity::setCurrentFrame(int x, int y, int w, int h) {
    this->currentFrame.x = x;
    this->currentFrame.y = y;
    this->currentFrame.w = w;
    this->currentFrame.h = h;
}

void Entity::setX(int x) {
    this->currentFrame.x = x;
}

void Entity::setY(int y) {
    this->currentFrame.y = y;
}
