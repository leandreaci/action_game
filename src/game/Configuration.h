//
// Created by leandro on 23/08/2021.
//

#ifndef ACTION_GAME_CONFIGURATION_H
#define ACTION_GAME_CONFIGURATION_H

#include <map>

class Configuration {

private:
    std::map<std::string, std::string> options;
    const char *filename = "../default.cfg";

public:
    void load();
};


#endif //ACTION_GAME_CONFIGURATION_H
