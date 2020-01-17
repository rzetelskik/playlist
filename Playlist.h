#ifndef PLAYLIST_PLAYLIST_H
#define PLAYLIST_PLAYLIST_H

#include "IMedia.h"
#include <cstddef>
#include <memory>
#include <utility>

class Playlist : public IMedia {
private:
public:
    explicit Playlist(std::string name) : IMedia(std::move(name)) {};
    void add(const std::shared_ptr<IMedia> &element);
    void add(const std::shared_ptr<IMedia> &element, size_t position);
    void remove();
    void remove(size_t position);
    void setMode(const IPlayMode mode);
    void play() override;
};


#endif //PLAYLIST_PLAYLIST_H
