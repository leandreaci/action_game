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

void Game::check() {
    Initialization init;
    init.check();
}

int Game::onExecute() {

    this->check();

    RenderWindow window(name, width, height);
    SDL_Texture *playerTexture = window.loadTexture("../res/gfx/main.png");
    Entity player(100, height - 50 * 4, playerTexture);
    player.setCurrentFrame(160, 0, 35, 50);

    SDL_Event Event;

    while (running) {
        while (SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }

        window.clear();
        window.render(player);
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

    Input input;
    input.onEvent(Event);
}

void Game::OnLoop() {

}

void Game::OnCleanup() {

}

void Game::OnRender() {

}