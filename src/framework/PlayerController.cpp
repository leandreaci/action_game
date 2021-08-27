//
// Created by leandro on 02/05/2020.
//

#include "Config.h"
#include <framework/Stage.h>
#include "PlayerController.h"
#include "Entity.h"

PlayerController::PlayerController(RenderWindow *window, Input *input) : window(window), input(input) {
    config = Config();
    config.load();
    sprintWidth = config.getSprintWidth();
    sprintHeight = config.getSprintHeight();
}

void PlayerController::init(const char *name) {
    this->entity = newEntity(name);
    this->setCurrentFrame(getSprintWidth(3), getSprintHeight(), getSprintWidth(), getSprintHeight());
}

int PlayerController::getSprintWidth(int position) {
    return this->sprintWidth * position;
}

int PlayerController::getSprintHeight(int position) {
    return this->sprintHeight * position;
}

void PlayerController::setCurrentFrame(int x, int y, int w, int h) {
    this->entity->setCurrentFrame(x, y, w, h);
}

void PlayerController::setCurrentFrameX(int x) {
    this->entity->setCurrentFrameX(x);
}

void PlayerController::setCurrentFrameY(int y) {
    this->entity->setCurrentFrameY(y);
}

Entity *PlayerController::newEntity(const char *name) {
    return new Entity(getSprintWidth(2), getSprintHeight(10), loadTexture(name));
}

SDL_Texture *PlayerController::loadTexture(const char *name) {
    return window->loadTexture(name);
}

void PlayerController::render() {
    window->render(this->entity);
}

void PlayerController::running() {
    if (!this->isJumping) {
        this->setCurrentFrame(0, getSprintHeight(4), sprintWidth, sprintHeight);
        this->entity->moveFrame(this->runningCurrentFrame);
        this->runningCurrentFrame++;
        if (this->runningCurrentFrame >= this->runningTotalFrames) {
            this->runningCurrentFrame = 0;
        }
    }
}

void PlayerController::stopped() {
    this->setCurrentFrame(getSprintWidth(3), sprintHeight, sprintWidth, sprintHeight);
}

void PlayerController::jumping() {
    if (this->jumpingCurrentFrame < this->jumpingTotalFrames) {
        this->setCurrentFrame(0, getSprintHeight(8), sprintWidth, sprintHeight);
        this->entity->moveFrame(this->jumpingCurrentFrame);
        this->jumpingCurrentFrame++;
    }
}

bool PlayerController::hasPlayerReachedTheGround() {
    return this->entity->getY() >= getSprintHeight(10);
}


void PlayerController::move(int direction) {
    if(direction == MOVE_FORWARD)
    {
        this->entity->setX( this->entity->getX() + velocity);
    }else
    {
        this->entity->setX( this->entity->getX() - velocity);
    }
}

void PlayerController::moveForward() {
    this->move(MOVE_FORWARD);
}

void PlayerController::moveBack() {
    this->move(MOVE_BACK);
}

void PlayerController::fire() {
    this->setCurrentFrameX( 0);
    this->setCurrentFrameY(getSprintHeight(2));
}

void PlayerController::flipHorizontal(bool on) {
    this->entity->flipHorizontal(on);
}

bool PlayerController::isWalkingForward() {
    this->input->isWalkForward();
}

bool PlayerController::isWalkingBack() {
    this->input->isWalkingBack();
}