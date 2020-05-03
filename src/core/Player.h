//
// Created by leandro on 02/05/2020.
//

#ifndef ACTION_GAME_PLAYER_H
#define ACTION_GAME_PLAYER_H

#include "RenderWindow.h"
#include "Entity.h"
#include "Input.h"

class Player {

public:
    explicit Player(RenderWindow *window, Input *input);
    void load();
    void render();
    void update();
    Entity* getEntity();
    SDL_Texture* getPlayerTexture();

private:
    Entity *entity;
    SDL_Texture *playerTexture;
    RenderWindow *window;
    Input *input;
};


#endif //ACTION_GAME_PLAYER_H
