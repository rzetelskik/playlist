#include "Playlist.h"
#include "PlayerException.h"
#include <iostream>

void Playlist::add(const std::shared_ptr<IPlayable> &element) {
    if (element->contains(this)) {
        throw PlaylistCycleException();
    }
    vector.push_back(element);
}

void Playlist::add(const std::shared_ptr<IPlayable> &element, size_t position) {
    if (element->contains(this))
        throw PlaylistCycleException();
    if (position > vector.size())
        throw PlaylistOutOfRangeException();
    auto it = vector.emplace(vector.begin() + position, element);
}

void Playlist::remove() {
    if (vector.empty())
        throw EmptyPlaylistException();
    vector.pop_back();
}

void Playlist::remove(size_t position) {
    if (position > vector.size())
        throw PlaylistOutOfRangeException();
    vector.erase(vector.begin() + position);
}

void Playlist::setMode(const std::shared_ptr<IPlayMode> &mode) {
    playMode = mode;
}

void Playlist::play() {
    std::cout << "Playlist [" << name << "]" << std::endl;
    playMode->play(vector);
}

bool Playlist::contains(const IPlayable *entity) const {
    if (entity == this)
        return true;

    for (const auto &element: vector) {
        if (element->contains(entity))
            return true;
    }

    return false;
}
