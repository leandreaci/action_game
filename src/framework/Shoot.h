//
// Created by leandro on 27/08/2021.
//

#ifndef ACTION_GAME_SHOOT_H
#define ACTION_GAME_SHOOT_H


#include "RenderWindow.h"

class Shoot {

public:
    Entity *shootEntity;
    RenderWindow *window;
    int direction = 1;
    int MOVE_FORWARD = 1;
    int MOVE_BACK = 2;

    void init(const char* path);

    void render();

    void update();

    void setWindow(RenderWindow *window);

    void fire(int x, int y);

    void setDirection(int direction);


};


#endif //ACTION_GAME_SHOOT_H
