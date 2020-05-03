//
// Created by leandro on 02/05/2020.
//

#ifndef ACTION_GAME_PLAYER_H
#define ACTION_GAME_PLAYER_H

#include "RenderWindow.h"
#include "Entity.h"

class Player {

public:
    explicit Player(RenderWindow *window);
    void load();
    void render();
    Entity* getEntity();
    SDL_Texture* getPlayerTexture();

private:
    Entity *entity;
    SDL_Texture *playerTexture;
    RenderWindow *window;
};


#endif //ACTION_GAME_PLAYER_H
