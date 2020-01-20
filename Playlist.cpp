#include "Playlist.h"
#include <iostream>

//TODO exceptions!!!!!!!!!!

void Playlist::add(const std::shared_ptr<IPlayable> &element) {
    vector.push_back(element);
}

void Playlist::add(const std::shared_ptr<IPlayable> &element, size_t position) {
    auto it = vector.emplace(vector.begin() + position, element);
}

void Playlist::remove() {
    vector.pop_back();
}

void Playlist::remove(size_t position) {
    vector.erase(vector.begin() + position);
}

void Playlist::setMode(const std::shared_ptr<IPlayMode> &mode) {
    playMode = mode;
}

void Playlist::play() {
    std::cout << "Playlist [" << name << "]" << std::endl;
    playMode->play(vector);
}
