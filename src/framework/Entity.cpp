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

void Entity::setCurrentFrameX(int x) {
    this->currentFrame.x = x;
}

void Entity::setCurrentFrameY(int y) {
    this->currentFrame.y = y;
}


void Entity::moveFrame(int frame) {
    this->currentFrame.x = (frame * this->currentFrame.w);
}

void Entity::setX(float axiosX) {
//    this->currentFrame.axiosX = axiosX;
    this->x = axiosX;
//    this->currentFrame.x = static_cast<int>(axiosX * 2);
}

void Entity::setY(float axiosY) {
    this->y = axiosY;
}

bool Entity::flipHorizontalVertical() {
    return this->flipEntityHorizontal && this->flipEntityVertical;
}

bool Entity::flipHorizontal() {
    return this->flipEntityHorizontal;
}

bool Entity::flipVertical() {
    return this->flipEntityVertical;
}

void Entity::flipHorizontalVertical(bool val) {
    this->flipEntityHorizontal = val;
    this->flipEntityVertical = val;
}

void Entity::flipHorizontal(bool val) {
    this->flipEntityHorizontal = val;
}

void Entity::flipVertical(bool val) {
    this->flipEntityVertical = val;
}

bool Entity::isFlipEntityHorizontal() const {
    return flipEntityHorizontal;
}

bool Entity::isFlipEntityVertical() const {
    return flipEntityVertical;
}
