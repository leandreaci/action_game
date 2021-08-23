//
// Created by leandro on 23/08/2021.
//

#ifndef ACTION_GAME_CONFIGURATION_H
#define ACTION_GAME_CONFIGURATION_H

#include <map>

class Configuration {

private:
    const char *filename = "../default.cfg";
    const char *SCREEN_WIDTH_KEY = "SCREEN_WIDTH";
    const char *SCREEN_HEIGHT_KEY = "SCREEN_HEIGHT";

    std::map<std::string, std::string> options;

public:
    void load();
    int getScreenWidth();
    int getScreenHeight();
};


#endif //ACTION_GAME_CONFIGURATION_H
