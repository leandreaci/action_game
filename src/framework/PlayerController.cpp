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

void PlayerController::update() {

    if(this->input->isWalkForward()){
        std::cout << "walking" << std::endl;
        this->entity->setX( this->entity->getX() + velocity);
        this->entity->flipHorizontal(false);
        this->running();
    } else if(this->input->isWalkingBack()){
        std::cout << "walking" << std::endl;
        this->entity->setX( this->entity->getX() - velocity);
        this->entity->flipHorizontal(true);
        this->running();
    } else if(this->input->isFire()) {
        std::cout << "Fire" << std::endl;

        this->entity->setCurrentFrameX( 0);
        this->entity->setCurrentFrameY( 50 * 2);
    }
    else {
        if(!this->isJumping) {
            this->stopped();
        }
    }

    if(this->input->isJumping()){
        std::cout << "jumping" << std::endl;
        this->isJumping = true;
    }

    if(this->isJumping) {
        this->entity->setY( this->entity->getY() - this->jumpForce * 1.8);
        this->jumpForce = this->jumpForce - (this->entity->getY() * 0.009);
        this->jumping();
    }

    if(this->hasPlayerReachedTheGround()) {
        this->isJumping = false;
        this->entity->setY(520);
        this->jumpForce = this->entity->getY() * 0.05;
        this->jumpingCurrentFrame = 0;
//        std::cout << "reached the ground" << std::endl;
    }
}

void PlayerController::running() {
    if(!this->isJumping) {
        this->entity->setCurrentFrame(0, 203, 50.3, 40);
        this->entity->moveFrame(this->runningCurrentFrame);
        this->runningCurrentFrame++;
        if(this->runningCurrentFrame >= this->runningTotalFrames) {
            this->runningCurrentFrame = 0;
        }
    }
}

void PlayerController::stopped() {
    this->entity->setCurrentFrame(50.3 * 3, 54, 50.3, 40);
    //this->entity->moveFrame(this->runningCurrentFrame);
    //this->runningCurrentFrame++;
    //if(this->runningCurrentFrame >= this->runningTotalFrames) {
    //    this->runningCurrentFrame = 0;
    //}
}

void PlayerController::jumping() {
    if(this->jumpingCurrentFrame < this->jumpingTotalFrames) {
        this->entity->setCurrentFrame(0, 403, 50.3, 40);
        this->entity->moveFrame(this->jumpingCurrentFrame);
        this->jumpingCurrentFrame++;
    }
}

bool PlayerController::hasPlayerReachedTheGround() {
    return this->entity->getY() >= 520;
}

Entity* PlayerController::getEntity() {
    return this->entity;
}

SDL_Texture *PlayerController::getPlayerTexture() {
    return this->playerTexture;
}