//
// Created by leandro on 02/05/2020.
//

#include <iostream>
#include "Input.h"

Input::Input() {
    struct Keys ActiveKeys;
}

void Input::onEvent(SDL_Event *Event) {

    if(Event->type == SDL_KEYDOWN)
    {
        SDL_Keysym key = Event->key.keysym;
        std::cout << "KEYDOWN" << std::endl;

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
            default:
                break;
        }

        printCurrentEvent();

    }
}

void Input::printCurrentEvent() {
    std::cout << "UP: " << ActiveKeys.up << std::endl;
    std::cout << "DOWN: " << ActiveKeys.down << std::endl;
    std::cout << "LEFT: " << ActiveKeys.left << std::endl;
    std::cout << "RIGHT: " << ActiveKeys.right << std::endl;
}
