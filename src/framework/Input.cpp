//
// Created by leandro on 02/05/2020.
//

#include <iostream>
#include "Input.h"

Input::Input() {
    struct Keys ActiveKeys;
}

void Input::reset() {
    ActiveKeys.up = false;
    ActiveKeys.down = false;
    ActiveKeys.left = false;
    ActiveKeys.right = false;
    ActiveKeys.space = false;
}

void Input::onEvent(SDL_Event *Event) {

    if(Event->type == SDL_KEYDOWN)
    {
        SDL_Keysym key = Event->key.keysym;
//        std::cout << "KEYDOWN" << std::endl;

        switch(key.sym)
        {
            case SDLK_UP:
                ActiveKeys.up = true;
                break;
            case SDLK_DOWN:
                ActiveKeys.down = true;
                break;
            case SDLK_RIGHT:
                ActiveKeys.right = true;
                break;
            case SDLK_LEFT:
                ActiveKeys.left = true;
                break;
            case SDLK_SPACE:
                ActiveKeys.space = true;
                break;
            default:
                break;
        }

//        printCurrentEvent();
//        reset();
    }

    if(Event->type == SDL_KEYUP)
    {
        SDL_Keysym key = Event->key.keysym;
        std::cout << "KEYUP" << std::endl;

        switch(key.sym)
        {
            case SDLK_UP:
                ActiveKeys.up = false;
                break;
            case SDLK_DOWN:
                ActiveKeys.down = false;
                break;
            case SDLK_RIGHT:
                ActiveKeys.right = false;
                break;
            case SDLK_LEFT:
                ActiveKeys.left = false;
                break;
            case SDLK_SPACE:
                ActiveKeys.space = false;
                break;
            default:
                break;
        }

        printCurrentEvent();
//        reset();


    }
}

void Input::printCurrentEvent() {
    std::cout << "UP: " << ActiveKeys.up << std::endl;
    std::cout << "DOWN: " << ActiveKeys.down << std::endl;
    std::cout << "LEFT: " << ActiveKeys.left << std::endl;
    std::cout << "RIGHT: " << ActiveKeys.right << std::endl;
    std::cout << "SPACE: " << ActiveKeys.right << std::endl;
}

bool Input::isWalkForward() {
    return ActiveKeys.right;
}

bool Input::isWalkingBack() {
    return ActiveKeys.left;
}

bool Input::isJumping() {
    return ActiveKeys.space;
}
