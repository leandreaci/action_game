//
// Created by leandro on 02/05/2020.
//

#ifndef ACTION_GAME_PLAYERCONTROLLER_H
#define ACTION_GAME_PLAYERCONTROLLER_H

#include "RenderWindow.h"
#include "Entity.h"
#include "Input.h"

class PlayerController {

public:
    explicit PlayerController(RenderWindow *window, Input *input);

    void render();

    virtual void update();

    virtual void running();

    virtual void stopped();

    virtual void jumping();

    virtual bool hasPlayerReachedTheGround();

    void init(const char* name);

protected:
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

    SDL_Texture * loadTexture(const char *name);

    Entity *newEntity(const char *name);

    void setCurrentFrame(int x, int y, int w, int h);

    void setCurrentFrameX(int x);

    void setCurrentFrameY(int y);
};


#endif //ACTION_GAME_PLAYERCONTROLLER_H
