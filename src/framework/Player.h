//
// Created by leandro on 02/05/2020.
//

#ifndef ACTION_GAME_PLAYER_H
#define ACTION_GAME_PLAYER_H

#include "RenderWindow.h"
#include "Entity.h"
#include "Input.h"

class Player {

public:
    explicit Player(RenderWindow *window, Input *input);
    void load();
    void render();
    void update();
    void running();
    void stopped();
    void jumping();
    bool hasPlayerReachedTheGround();
    Entity* getEntity();
    SDL_Texture* getPlayerTexture();

private:
    Entity *entity;
    SDL_Texture *playerTexture;
    RenderWindow *window;
    Input *input;
    float velocity = 20;

    float gravity = 9;
    float jumpForce = 160;

    bool isJumping = false;

    float runningCurrentFrame = 0;
    float runningTotalFrames = 8;

    float jumpingCurrentFrame = 0;
    float jumpingTotalFrames = 7;
};


#endif //ACTION_GAME_PLAYER_H
