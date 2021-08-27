//
// Created by leandro on 23/08/2021.
//

#include <framework/RenderWindow.h>
#include "Stage.h"
#include "Config.h"

Stage::Stage(RenderWindow *window) {
    this->window = window;
}

void Stage::render() {
    window->render(this->entity);
}

void Stage::init(const char* path) {
    Config config;
    config.load();

    backgroundTexture = this->window->loadTexture(path);
    entity = new Entity(-200, -400, backgroundTexture);
    entity->setCurrentFrame(0, 0, config.getScreenWidth(), config.getScreenHeight());
}

