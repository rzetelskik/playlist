#ifndef LIB_PLAYLIST_H
#define LIB_PLAYLIST_H

#include <exception>

class PlayerException : public std::exception {
    [[nodiscard]] const char *what() const noexcept override {
        return "PlayerException";
    }
};

class Player {

};

#endif //LIB_PLAYLIST_H