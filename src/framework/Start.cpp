//
// Created by leandro on 25/08/2021.
//

#include <game/ConfigurationGame.h>
#include <game/InputGame.h>
#include "framework/RenderWindow.h"
#include "framework/Initialization.h"
#include "framework/PlayerController.h"
#include "framework/graphic/FrameRate.h"
#include <framework/Stage.h>
#include "Start.h"

Start::Start(RenderWindow renderWindow, PlayerController player, Stage stage)
        : renderWindow(renderWindow), player(player), stage(stage) {
    this->config = ConfigurationGame();
    this->config.load();
    this->event = SDL_Event();
    this->frameRate = FrameRate();
    this->input = InputGame();
    this->renderWindow = RenderWindow(this->config.getName(), this->config.getScreenWidth(), this->config.getScreenHeight());
    this->player = PlayerController(&this->renderWindow, &this->input);
}

void Start::check() {
    Initialization init;
    init.check();
}

int Start::onExecute() {
    this->check();

    BeforeLoop();

    while (running) {
        this->frameRate.initialize();

        while (SDL_PollEvent(&this->event)) {
            OnEvent(&this->event);
        }

        OnCleanup();
        OnLoop();
        OnRender();

        this->frameRate.calculate();
    }

    return 0;
}

void Start::OnEvent(SDL_Event *Event) {

    if (Event->type == SDL_QUIT) {
        running = false;
    }

    this->input.onEvent(Event);
}


void Start::OnRender() {

}

