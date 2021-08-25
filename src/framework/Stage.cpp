//
// Created by leandro on 23/08/2021.
//

#include <framework/RenderWindow.h>
#include "Stage.h"
#include "game/ConfigurationGame.h"

Stage::Stage(RenderWindow *window) {
    this->window = window;
}

void Stage::loadBackground() {

    ConfigurationGame config;
    config.load();

    backgroundTexture = this->window->loadTexture("../res/gfx/stage_1.png");
    entity = new Entity(-200, -400, backgroundTexture);
    entity->setCurrentFrame(0, 0, config.getScreenWidth(), config.getScreenHeight());
}

void Stage::render() {
    window->render(this->entity);
}

