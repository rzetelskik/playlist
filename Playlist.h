#ifndef PLAYLIST_PLAYLIST_H
#define PLAYLIST_PLAYLIST_H

#include "IPlayable.h"
#include "SequenceMode.h"
#include "IPlayMode.h"
#include <cstddef>
#include <memory>
#include <utility>
#include <vector>

class Playlist : public IPlayable {
private:
    std::vector<std::shared_ptr<IPlayable>> vector;
    std::shared_ptr<IPlayMode> playMode;
    std::string name;
public:
    bool contains(const IPlayable *entity) const override;
    explicit Playlist(std::string name) : name(std::move(name)), playMode(createSequenceMode()) {};
    ~Playlist() override = default;
    void add(const std::shared_ptr<IPlayable> &element);
    void add(const std::shared_ptr<IPlayable> &element, size_t position);
    void remove();
    void remove(size_t position);
    void setMode(const std::shared_ptr<IPlayMode> &mode);
    void play() override;
};


#endif //PLAYLIST_PLAYLIST_H
