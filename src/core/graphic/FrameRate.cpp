//
// Created by leandro on 22/03/2021.
//

#include <SDL2/SDL.h>
#include "FrameRate.h"

void FrameRate::initialize() {
    lastTime = SDL_GetTicks();
}

Uint32 FrameRate::getFrameRate() {
    return frameRate;
}

void FrameRate::calculate() {
    Uint32 current = SDL_GetTicks();
    delta += current = lastTime;
    lastTime = current;
    frameRate++;

    if( delta > 1000 ) {
        delta -= 1000;
        frameRate = 0;
    }
}