//
// Created by leandro on 27/08/2021.
//

#include "Shoot.h"

void Shoot::render() {
    this->window->render(shootEntity);
}

void Shoot::update() {

    int sprintHeight = 50;

    if(this->shootEntity->getX() > 0)
    {
        if(this->direction == this->MOVE_FORWARD)
        {
            this->shootEntity->setX(  this->shootEntity->getX() + (sprintHeight));
        }else{
            this->shootEntity->setX(  this->shootEntity->getX() + sprintHeight * (-1));
        }
    }

    if(this->shootEntity->getX() > 1280)
    {
        this->shootEntity->setX(-500);
    }

}

void Shoot::setWindow(RenderWindow *window) {
    this->window = window;
}

void Shoot::fire(int x, int y) {

    int diffPosition;

    if(this->direction == 1)
    {
        diffPosition = 0;
    }else{
        diffPosition = -180;
    }

    this->shootEntity->setX(x + diffPosition);
    this->shootEntity->setY(y);
}

void Shoot::init(const char* path) {
    SDL_Texture *shootTexture = this->window->loadTexture(path);
    this->shootEntity = new Entity(0, 0, shootTexture);
    this->shootEntity->setCurrentFrame(this->shootEntity->getX(), this->shootEntity->getY(), 10, 10);
}

void Shoot::setDirection(int direction) {
    this->direction = direction;
}
