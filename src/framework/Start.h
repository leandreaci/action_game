//
// Created by leandro on 25/08/2021.
//

#ifndef ACTION_GAME_START_H
#define ACTION_GAME_START_H

#include <SDL.h>
#include "framework/Input.h"

class Start {
public:
    int onExecute();
    void OnEvent(SDL_Event *Event);
    void OnLoop();
    void OnCleanup();
    void OnRender();

private:
    bool running = true;
    const char* name = "Action Game";
    int width = 1280;
    int height = 720;
    void check();
    Input *input{};
};



#endif //ACTION_GAME_START_H
