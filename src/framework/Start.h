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
#include "framework/PlayerController.h"
#include "framework/Stage.h"

class Start {
public:
    explicit Start(RenderWindow renderWindow, PlayerController player, Stage stage);

    int onExecute();

    void OnEvent(SDL_Event *Event);

    virtual void OnLoop();

    virtual void OnCleanup();

    virtual void OnRender();

    virtual void BeforeLoop();

private:
    bool running = true;

    void check();

    RenderWindow renderWindow;
    Config config;
    SDL_Event event;
    FrameRate frameRate;
    Input input;
    PlayerController player;
    Stage stage;
};


#endif //ACTION_GAME_START_H
