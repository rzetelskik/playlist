//
// Created by bartosz on 1/19/20.
//

#ifndef PLAYLIST_PLAYEREXCEPTION_H
#define PLAYLIST_PLAYEREXCEPTION_H

#include <iostream>


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


#endif //PLAYLIST_PLAYEREXCEPTION_H
