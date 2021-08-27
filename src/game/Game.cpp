//
// Created by leandro on 21/04/2020.
//

#include "Game.h"

void Start::BeforeLoop() {
    this->renderWindow.init();
    this->player.setWindow(&this->renderWindow);
    this->stage = Stage(&this->renderWindow);
    this->player.init("../res/gfx/megaman-sprite.png");
    this->stage.init("../res/gfx/stage_1.png");
}


void Start::OnLoop() {
    this->stage.render();
    this->player.render();
    this->player.update();
    this->renderWindow.display();
}

void Start::OnCleanup() {
    this->renderWindow.clear();
}
