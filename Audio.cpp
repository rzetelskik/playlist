#include <iostream>
#include "Audio.h"

void Audio::play() {
    std::cout << "Song " << "[" << metaData.at("artist") << ", " << metaData.at("title") << "]: " << content
              << std::endl;
}
