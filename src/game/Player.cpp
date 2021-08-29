//
// Created by leandro on 27/08/2021.
//

#include "Player.h"

void PlayerController::update() {

    this->shoot.update();

    if(this->isWalkingForward()){
        this->moveForward();
        this->flipHorizontal();
        this->running();
    } else if(this->isWalkingBack()){
        this->moveBack();
        this->flipHorizontal(true);
        this->running();
    } else if(this->input->isFire()) {
        this->fire();
    }
    else {
        if(!this->isJumping) {
            this->stopped();
        }
    }

    if(this->input->isJumping()){
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
    }
}