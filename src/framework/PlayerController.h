//
// Created by leandro on 02/05/2020.
//

#ifndef ACTION_GAME_PLAYERCONTROLLER_H
#define ACTION_GAME_PLAYERCONTROLLER_H

#include "RenderWindow.h"
#include "Config.h"
#include "Entity.h"
#include "Input.h"
#include "Shoot.h"

class PlayerController {

public:

    PlayerController(RenderWindow *window, Input *input);

    int MOVE_FORWARD = 1;
    int MOVE_BACK = 2;
    int current_direction;

    void render();

    virtual void update();

    virtual void running();

    virtual void stopped();

    virtual void jumping();

    virtual bool hasPlayerReachedTheGround();

    void init(const char *name);

    void setWindow(RenderWindow *window);

protected:
    Entity *entity;
    SDL_Texture *playerTexture;


    RenderWindow *window;
    Input *input;
    Config config;
    Shoot shoot;

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

    void move(int direction);

    void moveForward();

    void moveBack();

    void fire();

    void flipHorizontal(bool on = false);

    bool isWalkingForward();

    bool isWalkingBack();


};


#endif //ACTION_GAME_PLAYERCONTROLLER_H
