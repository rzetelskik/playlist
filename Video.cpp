#include "Video.h"
#include "PlayerException.h"
#include <iostream>

FileContent Video::decodeROT13(const FileContent &content) {
    FileContent decoded;
    for (char c : content) {
        decoded.append(1, c + ((isalpha(c)) ? (((tolower(c) - 'a') < 13) ? 13 : -13) : 0));
    }

    return decoded;
}

void Video::play() {
    std::cout << "Movie " << "[" << metaData.at("title") << ", " << metaData.at("year") << "]: " << content
              << std::endl;
}

Video::Video(const MetaData &metaData, const FileContent &content) :
        IMedia(metaData, decodeROT13(content)) {
        if (metaData.find("year") == metaData.end() ||
            metaData.find("title") == metaData.end()) {
            throw InsufficientMetaDataException();
        }
}


