//
// Created by leandro on 21/04/2020.
//

#ifndef INC_2D_RGP_EXAMPLE_SDL2_GAME_H
#define INC_2D_RGP_EXAMPLE_SDL2_GAME_H

#include <SDL.h>

class Game {
public:
    int onExecute();
    void OnEvent(SDL_Event *Event);
    void OnLoop();
    void OnCleanup();
    void OnRender();

private:
    bool running = true;
    const char* name = "2D RPG";
    int width = 1280;
    int height = 720;
    void check();
};


#endif //INC_2D_RGP_EXAMPLE_SDL2_GAME_H
