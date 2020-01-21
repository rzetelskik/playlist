#include <iostream>
#include "Audio.h"
#include "PlayerException.h"

void Audio::play() {
    std::cout << "Song " << "[" << metaData.at("artist") << ", " << metaData.at("title") << "]: " << content
              << std::endl;
}

Audio::Audio(const MetaData &metaData, const FileContent &content) :
        IMedia(metaData, content) {
    if (metaData.find("artist") == metaData.end() ||
        metaData.find("title") == metaData.end()) {
        throw InsufficientMetaDataException();
    }
};