#ifndef LIB_PLAYLIST_H
#define LIB_PLAYLIST_H

#include "Playable.h"
#include "File.h"
#include "Playlist.h"
#include <exception>
#include <memory>



class Player {
private:

public:
    std::shared_ptr<const Playable> openFile(const File &file); //TODO check consts
    std::shared_ptr<const Playlist> createPlaylist(const std::string& name);
};

#endif //LIB_PLAYLIST_H