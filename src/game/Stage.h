//
// Created by leandro on 23/08/2021.
//

#ifndef ACTION_GAME_STAGE_H
#define ACTION_GAME_STAGE_H

#include <framework/Entity.h>
#include <framework/RenderWindow.h>

class Stage {
public:
    explicit Stage(RenderWindow *window);

    Entity *entity;
    SDL_Texture *backgroundTexture;
    RenderWindow *window;

    void loadBackground();

    void render();


};


#endif //ACTION_GAME_STAGE_H
