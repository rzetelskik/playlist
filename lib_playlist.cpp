#include "lib_playlist.h"
#include <memory>

std::shared_ptr<Playlist> Player::createPlaylist(const std::string &name) {
    return std::make_shared<Playlist>(name);
}

std::shared_ptr<IMedia> Player::openFile(const File &file) {
    try {
        return factoryMapping.at(file.getFileType())(file.getMetaData(), file.getFileContent());
    } catch (std::out_of_range &e) {
        throw UnsupportedTypeException();
    }
}
