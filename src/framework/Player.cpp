//
// Created by leandro on 02/05/2020.
//

#include <iostream>
#include "Player.h"
#include "Entity.h"

void Player::load() {
    playerTexture = window->loadTexture("../res/gfx/megaman-sprite.png");
    this->entity = new Entity(100, 520, playerTexture);
    this->entity->setCurrentFrame(150, 55, 50, 40);
}

void Player::render()
{
    window->render(this->entity);
}

void Player::update() {

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
    } else {
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

void Player::running() {
    if(!this->isJumping) {
        this->entity->setCurrentFrame(0, 203, 50.3, 40);
        this->entity->moveFrame(this->runningCurrentFrame);
        this->runningCurrentFrame++;
        if(this->runningCurrentFrame >= this->runningTotalFrames) {
            this->runningCurrentFrame = 0;
        }
    }
}

void Player::stopped() {
    this->entity->setCurrentFrame(50.3 * 3, 54, 50.3, 40);
    //this->entity->moveFrame(this->runningCurrentFrame);
    //this->runningCurrentFrame++;
    //if(this->runningCurrentFrame >= this->runningTotalFrames) {
    //    this->runningCurrentFrame = 0;
    //}
}

void Player::jumping() {
    if(this->jumpingCurrentFrame < this->jumpingTotalFrames) {
        this->entity->setCurrentFrame(0, 403, 50.3, 40);
        this->entity->moveFrame(this->jumpingCurrentFrame);
        this->jumpingCurrentFrame++;
    }
}

bool Player::hasPlayerReachedTheGround() {
    return this->entity->getY() >= 520;
}

Entity* Player::getEntity() {
    return this->entity;
}

SDL_Texture *Player::getPlayerTexture() {
    return this->playerTexture;
}

Player::Player(RenderWindow *window, Input *input): window(window), input(input) {
    this->load();
}


