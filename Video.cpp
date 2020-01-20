#include "Video.h"
#include <iostream>

void Video::play() {
    std::cout << "Movie " << "[" << metaData.at("title") << ", " << metaData.at("year") << "]: " << content << std::endl;
}
