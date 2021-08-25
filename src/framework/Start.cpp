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

void Start::check() {
    Initialization init;
    init.check();
}

int Start::onExecute() {
    SDL_Event Event;
    ConfigurationGame config;
    config.load();

    this->check();
    this->input = new InputGame;

    FrameRate frameRate;
    RenderWindow window(name, config.getScreenWidth(), config.getScreenHeight());
    PlayerController player1(&window, this->input);
    Stage stage(&window);
    stage.loadBackground();

    while (running) {
        frameRate.initialize();

        while (SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }

        window.clear();
        stage.render();
        player1.render();
        player1.update();
        window.display();

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