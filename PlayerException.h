#ifndef PLAYLIST_PLAYEREXCEPTION_H
#define PLAYLIST_PLAYEREXCEPTION_H

class PlayerException : public std::exception {
public:
    [[nodiscard]] const char *what() const noexcept override {
        return "player exception";
    }
};

class UnsupportedTypeException : public PlayerException {
public:
    [[nodiscard]] const char *what() const noexcept override {
        return "unsupported type";
    }
};

class CorruptFileException : public PlayerException {
public:
    [[nodiscard]] const char *what() const noexcept override {
        return "corrupt file";
    }
};

class CorruptContentException : public PlayerException {
public:
    [[nodiscard]] const char *what() const noexcept override {
        return "corrupt content";
    }
};

#endif //PLAYLIST_PLAYEREXCEPTION_H