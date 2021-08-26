//
// Created by leandro on 02/05/2020.
//

#ifndef ACTION_GAME_INPUT_H
#define ACTION_GAME_INPUT_H


#include <SDL_keyboard.h>
#include <SDL_events.h>

class Input {

protected:

    struct Keys {
        bool up = false;
        bool down = false;
        bool left = false;
        bool right = false;
        bool space = false;
        bool fire = false;
    };

    Keys ActiveKeys;

public:
    Input();
    void onEvent(SDL_Event *Event);
    void printCurrentEvent();
    bool isWalkForward();
    bool isJumping();
    void reset();
    bool isWalkingBack();

    bool isFire();
};


#endif //ACTION_GAME_INPUT_H
