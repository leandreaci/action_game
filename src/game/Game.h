//
// Created by leandro on 21/04/2020.
//

#ifndef INC_ACTION_GAME_GAME_H
#define INC_ACTION_GAME_GAME_H

#include <SDL.h>
#include <framework/Start.h>
#include "framework/Input.h"
#include "framework/Stage.h"
#include "game/Player.h"

class Game : public Start {

public:
    Game() : Start(RenderWindow(nullptr, 0, 0), Player(nullptr, nullptr), Stage(nullptr)) {}
};


#endif //INC_ACTION_GAME_GAME_H
