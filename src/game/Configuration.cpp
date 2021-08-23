//
// Created by leandro on 23/08/2021.
//

#include <fstream>
#include <iostream>
#include "Configuration.h"

void Configuration::load() {

    std::ifstream file;

    file.open(this->filename);

    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            line.erase(std::remove_if(line.begin(), line.end(), isspace),
                       line.end());
            if (line.empty() || line[0] == '#') {
                continue;
            }
            auto delimiterPos = line.find('=');
            auto name = line.substr(0, delimiterPos);
            auto value = line.substr(delimiterPos + 1);
            this->options.insert({name, value});
        }

        file.close();
    }

}

int Configuration::getScreenWidth() {
    return stoi(this->options.find(this->SCREEN_WIDTH_KEY)->second);
}

int Configuration::getScreenHeight() {
    return stoi(this->options.find(this->SCREEN_HEIGHT_KEY)->second);
}

int Configuration::getFps() {
    return stoi(this->options.find(this->FPS)->second);
}
