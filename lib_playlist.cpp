#include "lib_playlist.h"
#include <memory>

std::shared_ptr<const IMedia> Player::openFile(const File &file) {
    return nullptr;
}

std::shared_ptr<const Playlist> Player::createPlaylist(const std::string &name) {
    return std::make_shared<Playlist>(name);
}
