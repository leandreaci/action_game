//
// Created by leandro on 02/05/2020.
//

#ifndef ACTION_GAME_PLAYERCONTROLLER_H
#define ACTION_GAME_PLAYERCONTROLLER_H

#include "RenderWindow.h"
#include "Config.h"
#include "Entity.h"
#include "Input.h"

class PlayerController {

public:

    PlayerController(RenderWindow *window, Input *input);

    void render();

    virtual void update();

    virtual void running();

    virtual void stopped();

    virtual void jumping();

    virtual bool hasPlayerReachedTheGround();

    void init(const char *name);

protected:
    Entity *entity;
    SDL_Texture *playerTexture;


    RenderWindow *window;
    Input *input;
    Config config;

    int sprintWidth;
    int sprintHeight;
    float velocity = 20;
    float gravity = 9;
    float jumpForce = 160;
    float runningCurrentFrame = 0;
    float runningTotalFrames = 8;
    float jumpingCurrentFrame = 0;
    float jumpingTotalFrames = 7;
    bool isJumping = false;

    Entity *newEntity(const char *name);

    void setCurrentFrame(int x, int y, int w, int h);

    void setCurrentFrameX(int x);

    void setCurrentFrameY(int y);

    SDL_Texture *loadTexture(const char *name);

    int getSprintWidth(int position = 1);

    int getSprintHeight(int position = 1);
};


#endif //ACTION_GAME_PLAYERCONTROLLER_H
