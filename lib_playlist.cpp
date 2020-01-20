#include "lib_playlist.h"
#include <memory>
#include "FileParser.h"

std::shared_ptr<Playlist> Player::createPlaylist(const std::string &name) {
    return std::make_shared<Playlist>(name);
}

std::shared_ptr<IMedia> Player::openFile(const File &file) {
    ParsedFile parsedFile = fileParser.parse(file);
    try {
        return factoryMapping.at(parsedFile.first)(parsedFile.second.first, parsedFile.second.second);
    } catch (std::out_of_range &e) {
        throw UnsupportedTypeException();
    }
}
