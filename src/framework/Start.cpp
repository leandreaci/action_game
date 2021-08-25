//
// Created by leandro on 25/08/2021.
//

#include <game/ConfigurationGame.h>
#include <game/Stage.h>
#include <game/InputGame.h>
#include "framework/RenderWindow.h"
#include "framework/Initialization.h"
#include "framework/PlayerController.h"
#include "framework/graphic/FrameRate.h"
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
    this->renderWindow.init();

    BeforeLoop();

    while (running) {
        this->frameRate.initialize();

        while (SDL_PollEvent(&this->event)) {
            OnEvent(&this->event);
        }

        OnLoop();
        OnRender();

        this->frameRate.calculate();
        //        std::cout << frameRate.getFrameRate() << std::endl;
    }

    return 0;
}

void Start::OnEvent(SDL_Event *Event) {

    if (Event->type == SDL_QUIT) {
        running = false;
    }

    this->input.onEvent(Event);
}

void Start::OnLoop() {
    this->renderWindow.clear();
    this->stage.render();
    this->player.render();
    this->player.update();
    this->renderWindow.display();
}

void Start::OnCleanup() {

}

void Start::OnRender() {

}

void Start::BeforeLoop() {
    this->player.init();
    this->stage = Stage(&this->renderWindow);
    this->stage.loadBackground();
}
