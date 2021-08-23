//
// Created by leandro on 23/08/2021.
//

#ifndef ACTION_GAME_CAMERA_H
#define ACTION_GAME_CAMERA_H


#include <SDL_rect.h>

class Camera {

    SDL_Rect camera;
    const Uint16 SCREEN_WIDTH = 500;
    const Uint16 SCREEN_HEIGHT = 500;

    void move();

};


#endif //ACTION_GAME_CAMERA_H
