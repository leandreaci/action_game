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
}

void Start::check() {
    Initialization init;
    init.check();
}

int Start::onExecute() {
    SDL_Event Event;

    this->check();
    this->input = new InputGame;

    FrameRate frameRate;
    this->renderWindow.init();
    PlayerController player1(&this->renderWindow, this->input);
    Stage stage(&this->renderWindow);
    stage.loadBackground();

    while (running) {
        frameRate.initialize();

        while (SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }

        this->renderWindow.clear();
        stage.render();
        player1.render();
        player1.update();
        this->renderWindow.display();

        OnLoop();
        OnRender();

        frameRate.calculate();
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
