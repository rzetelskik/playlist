#ifndef LIB_PLAYLIST_H
#define LIB_PLAYLIST_H

#include "IPlayable.h"
#include "IMedia.h"
#include "Audio.h"
#include "Video.h"
#include "File.h"
#include "Playlist.h"
#include "ShuffleMode.h"
#include "OddEvenMode.h"
#include "PlayerException.h"
#include <exception>
#include <memory>
#include <functional>

using MapFunction = std::function<std::shared_ptr<IMedia>(const MetaData &metaData, const FileContent &content)>;

class Player {
private:
    const std::map<FileType, MapFunction> factoryMapping{
            {"audio", [](auto metaData, auto content) { return std::make_shared<Audio>(metaData, content); }},
            {"video", [](auto metaData, auto content) { return std::make_shared<Video>(metaData, content); }}
    };
public:
    Player() = default;
    ~Player() = default;
    std::shared_ptr<IMedia> openFile(const File &file); //TODO check consts
    std::shared_ptr<Playlist> createPlaylist(const std::string &name);
};

#endif //LIB_PLAYLIST_H