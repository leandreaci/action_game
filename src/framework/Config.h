//
// Created by leandro on 24/08/2021.
//

#ifndef ACTION_GAME_CONFIG_H
#define ACTION_GAME_CONFIG_H

#include <map>

class Config {

protected:
    const char *filename = "../default.cfg";
    const char *SCREEN_WIDTH_KEY = "SCREEN_WIDTH";
    const char *SCREEN_HEIGHT_KEY = "SCREEN_HEIGHT";
    const char *FPS = "FPS";

    std::map<std::string, std::string> options;

public:
    void load();

    int getScreenWidth();

    int getScreenHeight();

    int getFps();
};


#endif //ACTION_GAME_CONFIG_H
