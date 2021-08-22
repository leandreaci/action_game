//
// Created by leandro on 21/04/2020.
//
#include <SDL2/SDL.h>
#include <iostream>

#include "Entity.h"
#include "RenderWindow.h"
#include "Initialization.h"
#include "Game.h"
#include "Input.h"
#include "Player.h"
#include "graphic/FrameRate.h"

void Game::check() {
    Initialization init;
    init.check();
}

int Game::onExecute() {
    SDL_Event Event;

    this->check();
    this->input = new Input;

    RenderWindow window(name, width, height);
    Player player1(&window, this->input);
    FrameRate frameRate;


    while (running) {
        frameRate.initialize();

        while (SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }

        window.clear();
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