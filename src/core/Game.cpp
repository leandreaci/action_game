//
// Created by leandro on 21/04/2020.
//
#include <SDL2/SDL.h>
#include <iostream>

#include "core/Entity.h"
#include "core/RenderWindow.h"
#include "core/Initialization.h"
#include "Game.h"
#include "core/Input.h"
#include "core/Player.h"

void Game::check() {
    Initialization init;
    init.check();
}

int Game::onExecute() {

    this->check();

    SDL_Event Event;
    RenderWindow window(name, width, height);
    this->input = new Input;

    Player player1(&window, this->input);

    while (running) {
        while (SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }

        window.clear();
        player1.render();
        player1.update();
        window.display();

        OnLoop();
        OnRender();
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