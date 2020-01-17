#ifndef LIB_PLAYLIST_H
#define LIB_PLAYLIST_H

#include "IMedia.h"
#include "File.h"
#include "Playlist.h"
#include <exception>
#include <memory>

class PlayerException : public std::exception {
    [[nodiscard]] const char *what() const noexcept override {
        return "player exception";
    }
};

class UnsupportedTypeException : public PlayerException {
    [[nodiscard]] const char *what() const noexcept override {
        return "unsupported type";
    }
};

class CorruptFileException : public PlayerException {
    [[nodiscard]] const char *what() const noexcept override {
        return "corrupt file";
    }
};

class CorruptContentException : public PlayerException {
    [[nodiscard]] const char *what() const noexcept override {
        return "corrupt content";
    }
};

class Player {
private:

public:
    std::shared_ptr<const IMedia> openFile(const File &file); //TODO check consts
    std::shared_ptr<const Playlist> createPlaylist(const std::string& name);
};

#endif //LIB_PLAYLIST_H