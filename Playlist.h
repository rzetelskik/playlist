#ifndef PLAYLIST_PLAYLIST_H
#define PLAYLIST_PLAYLIST_H

#include "Playable.h"
#include "SequenceMode.h"
#include "IPlayMode.h"
#include <cstddef>
#include <memory>
#include <utility>
#include <vector>

class Playlist : public Playable {
private:
    std::vector<std::shared_ptr<Playable>> vector;
    std::shared_ptr<IPlayMode> playMode;
    std::string name;
public:
    explicit Playlist(const std::string &name) : name(name), playMode(createSequenceMode()) {};
    ~Playlist() override = default;
    void add(const std::shared_ptr<Playable> &element);
    void add(const std::shared_ptr<Playable> &element, size_t position);
    void remove();
    void remove(size_t position);
    void setMode(const std::shared_ptr<IPlayMode> &mode);
    void play() override;
};


#endif //PLAYLIST_PLAYLIST_H
