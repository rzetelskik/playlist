#include "lib_playlist.h"
#include <memory>
#include "FileParser.h"
#include "MediaFactory.h"
#include "PlayerException.h"

std::shared_ptr<const Playlist> Player::createPlaylist(const std::string &name) {
    return std::make_shared<Playlist>(name);
}

std::shared_ptr<const Playable> Player::openFile(const File &file) {
    FileParser parser;
    auto fileData = parser.parseFile(file);
    MediaFactory factory;
    //TODO moze zrobic jakis using FileData = tuple<......> ??
    return std::make_shared<Playable>(factory.createMedia(std::get<0>(fileData),
                                                          std::get<1>(fileData),
                                                          std::get<2>(fileData)));
}
