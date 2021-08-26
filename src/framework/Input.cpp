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
    ActiveKeys.fire = false;
}

void Input::onEvent(SDL_Event *Event) {

    if (Event->type == SDL_KEYDOWN) {
        SDL_Keysym key = Event->key.keysym;
//        std::cout << "KEYDOWN" << std::endl;

        switch (key.sym) {
            case SDLK_w:
                ActiveKeys.up = true;
                break;
            case SDLK_s:
                ActiveKeys.down = true;
                break;
            case SDLK_d:
                ActiveKeys.right = true;
                break;
            case SDLK_a:
                ActiveKeys.left = true;
                break;
            case SDLK_SPACE:
                ActiveKeys.space = true;
                break;
            case SDLK_RETURN:
                ActiveKeys.fire = true;
                break;
            default:
                break;
        }

//        printCurrentEvent();
//        reset();
    }

    if (Event->type == SDL_KEYUP) {
        SDL_Keysym key = Event->key.keysym;
//        std::cout << "KEYUP" << std::endl;

        switch (key.sym) {
            case SDLK_w:
                ActiveKeys.up = false;
                break;
            case SDLK_s:
                ActiveKeys.down = false;
                break;
            case SDLK_d:
                ActiveKeys.right = false;
                break;
            case SDLK_a:
                ActiveKeys.left = false;
                break;
            case SDLK_SPACE:
                ActiveKeys.space = false;
                break;
            case SDLK_RETURN:
                ActiveKeys.fire = false;
                break;
            default:
                break;
        }

//        printCurrentEvent();
//        reset();


    }
}

void Input::printCurrentEvent() {
    std::cout << "UP: " << ActiveKeys.up << std::endl;
    std::cout << "DOWN: " << ActiveKeys.down << std::endl;
    std::cout << "LEFT: " << ActiveKeys.left << std::endl;
    std::cout << "RIGHT: " << ActiveKeys.right << std::endl;
    std::cout << "SPACE: " << ActiveKeys.right << std::endl;
    std::cout << "Fire: " << ActiveKeys.fire << std::endl;
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

bool Input::isFire() {
    return ActiveKeys.fire;
}
