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

Start::Start(RenderWindow renderWindow) : renderWindow(renderWindow) {
    this->config = ConfigurationGame();
    this->config.load();
    this->renderWindow = RenderWindow(this->config.getName(), this->config.getScreenWidth(), this->config.getScreenHeight());
    this->event = SDL_Event();
    this->frameRate = FrameRate();
}

void Start::check() {
    Initialization init;
    init.check();
}

int Start::onExecute() {


    this->check();
    this->input = new InputGame;
    this->renderWindow.init();
    PlayerController player1(&this->renderWindow, this->input);
    Stage stage(&this->renderWindow);
    stage.loadBackground();

    while (running) {
        this->frameRate.initialize();

        while (SDL_PollEvent(&this->event)) {
            OnEvent(&this->event);
        }

        this->renderWindow.clear();
        stage.render();
        player1.render();
        player1.update();
        this->renderWindow.display();

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

    input->onEvent(Event);
}

void Start::OnLoop() {

}

void Start::OnCleanup() {

}

void Start::OnRender() {

}
