//
// Created by leandro on 25/08/2021.
//

#ifndef ACTION_GAME_START_H
#define ACTION_GAME_START_H

#include <SDL.h>
#include "framework/Input.h"
#include "framework/RenderWindow.h"
#include "framework/Config.h"
#include "framework/graphic/FrameRate.h"

class Start {
public:
    explicit Start(RenderWindow renderWindow);
    int onExecute();
    void OnEvent(SDL_Event *Event);
    void OnLoop();
    void OnCleanup();
    void OnRender();

private:
    bool running = true;
    void check();
    Input *input{};
    RenderWindow renderWindow;
    Config config;
    SDL_Event event;
    FrameRate frameRate;
};



#endif //ACTION_GAME_START_H
