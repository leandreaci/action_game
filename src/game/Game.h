//
// Created by leandro on 21/04/2020.
//

#ifndef INC_ACTION_GAME_GAME_H
#define INC_ACTION_GAME_GAME_H

#include <SDL.h>
#include "framework/Input.h"

class Game {
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


#endif //INC_2D_RGP_EXAMPLE_SDL2_GAME_H
