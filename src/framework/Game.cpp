//
// Created by leandro on 21/04/2020.
//
#include <SDL2/SDL.h>
#include <iostream>
#include <game/Configuration.h>
#include <game/Stage.h>

#include "Entity.h"
#include "RenderWindow.h"
#include "Initialization.h"
#include "Game.h"
#include "../game/InputGame.h"
#include "PlayerController.h"
#include "graphic/FrameRate.h"

void Game::check() {
    Initialization init;
    init.check();
}

int Game::onExecute() {
    SDL_Event Event;
    Configuration config;
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

void Game::OnEvent(SDL_Event *Event) {

    if (Event->type == SDL_QUIT) {
        running = false;
    }

    input->onEvent(Event);
}

void Game::OnLoop() {

}

void Game::OnCleanup() {

}

void Game::OnRender() {

}