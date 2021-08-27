//
// Created by leandro on 02/05/2020.
//

#include <iostream>
#include <game/ConfigurationGame.h>
#include <framework/Stage.h>
#include "PlayerController.h"
#include "Entity.h"

PlayerController::PlayerController(RenderWindow *window, Input *input): window(window), input(input) {
}

void PlayerController::init(const char* name) {
    this->entity = newEntity(name);
    this->setCurrentFrame(150, 55, 50, 40);
}

void PlayerController::setCurrentFrame(int x, int y, int w, int h)
{
    this->entity->setCurrentFrame(x, y, w ,h);
}

void PlayerController::setCurrentFrameX(int x)
{
    this->entity->setCurrentFrameX(x);
}

void PlayerController::setCurrentFrameY(int y)
{
    this->entity->setCurrentFrameY(y);
}

Entity * PlayerController::newEntity(const char* name) {
    return new Entity(100, 520, loadTexture(name));
}

SDL_Texture * PlayerController::loadTexture(const char* name) {
    return window->loadTexture(name);
}

void PlayerController::render()
{
    window->render(this->entity);
}


void PlayerController::running() {
    if(!this->isJumping) {
        this->setCurrentFrame(0, 203, 50.3, 40);
        this->entity->moveFrame(this->runningCurrentFrame);
        this->runningCurrentFrame++;
        if(this->runningCurrentFrame >= this->runningTotalFrames) {
            this->runningCurrentFrame = 0;
        }
    }
}

void PlayerController::stopped() {
    this->setCurrentFrame(50.3 * 3, 54, 50.3, 40);
    //this->entity->moveFrame(this->runningCurrentFrame);
    //this->runningCurrentFrame++;
    //if(this->runningCurrentFrame >= this->runningTotalFrames) {
    //    this->runningCurrentFrame = 0;
    //}
}

void PlayerController::jumping() {
    if(this->jumpingCurrentFrame < this->jumpingTotalFrames) {
        this->setCurrentFrame(0, 403, 50.3, 40);
        this->entity->moveFrame(this->jumpingCurrentFrame);
        this->jumpingCurrentFrame++;
    }
}

bool PlayerController::hasPlayerReachedTheGround() {
    return this->entity->getY() >= 520;
}
