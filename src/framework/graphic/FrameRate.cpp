//
// Created by leandro on 22/03/2021.
//

#include <SDL2/SDL.h>
#include <game/Configuration.h>
#include "FrameRate.h"

void FrameRate::initialize() {
    lastTime = SDL_GetTicks();
}

Uint32 FrameRate::getFrameRate() {
    return frameRate;
}

void FrameRate::calculate() {

    Configuration config;
    config.load();
    delta = SDL_GetTicks() - lastTime;

    if(delta < fps){
        frameRate = config.getFps() - delta;
        SDL_Delay(frameRate);
    }
}