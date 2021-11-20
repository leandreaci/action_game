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
    this->shoot = Shoot();
    this->shoot.setWindow(window);
    this->sprintWidth = config.getSprintWidth();
    this->sprintHeight = config.getSprintHeight();
    this->current_direction = MOVE_FORWARD;
}

void PlayerController::init(const char *name) {
    this->entity = newEntity(name);
    this->shoot.init("../res/gfx/shoot_10.png");
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
    this->shoot.render();
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
    this->current_direction = MOVE_FORWARD;
    this->move(MOVE_FORWARD);
}

void PlayerController::moveBack() {
    this->current_direction = MOVE_BACK;
    this->move(MOVE_BACK);
}

void PlayerController::fire() {
    this->setCurrentFrameX( 0);
    this->setCurrentFrameY(getSprintHeight(2));

    this->shoot.setDirection(this->current_direction);

    this->shoot.fire(this->entity->getX() + 170, this->entity->getY() + 65);
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

void PlayerController::setWindow(RenderWindow *window) {
    this->window = window;
}