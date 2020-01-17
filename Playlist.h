#ifndef PLAYLIST_PLAYLIST_H
#define PLAYLIST_PLAYLIST_H

#include "IMedia.h"
#include "SequenceMode.h"
#include "IPlayMode.h"
#include <cstddef>
#include <memory>
#include <utility>
#include <vector>

class Playlist : public IMedia {
private:
    std::vector<std::shared_ptr<IMedia>> vector;
    std::shared_ptr<IPlayMode> playMode;
public:
    explicit Playlist(const std::string &name) : IMedia(name), playMode(createSequenceMode()) {};
    ~Playlist() override = default;
    void add(const std::shared_ptr<IMedia> &element);
    void add(const std::shared_ptr<IMedia> &element, size_t position);
    void remove();
    void remove(size_t position);
    void setMode(const std::shared_ptr<IPlayMode> &mode);
    void play() override;
};


#endif //PLAYLIST_PLAYLIST_H
