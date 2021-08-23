//
// Created by leandro on 23/08/2021.
//

#include <fstream>
#include <filesystem>
#include <iostream>
#include "Configuration.h"

void Configuration::load() {

    std::ifstream file (this->filename);
    std::cout << "Reading File " << std::endl;
    std::cout << file.is_open() << std::endl;
    std::cout << std::filesystem::current_path() << std::endl;
    this->options = {{"1", "2"}};

}
