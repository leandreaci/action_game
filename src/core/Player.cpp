//
// Created by leandro on 02/05/2020.
//

#include "Player.h"
#include "Entity.h"

void Player::load() {
    playerTexture = window->loadTexture("../res/gfx/main.png");
    this->entity = new Entity(100, 720 - 50 * 4, playerTexture);
    this->entity->setCurrentFrame(160, 0, 35, 50);
}

void Player::render()
{
    window->render(this->entity);
}

void Player::update() {

    if(this->input->isWalkForward())
    {
        this->entity->setX( 1 );
    }
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


