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
    bool contains(const IPlayable *entity) const override;
public:
    explicit Playlist(const std::string &name) : name(name), playMode(createSequenceMode()) {};

    ~Playlist() override = default;

    void add(const std::shared_ptr<IPlayable> &element);

    void add(const std::shared_ptr<IPlayable> &element, size_t position);

    void remove();

    void remove(size_t position);

    void setMode(const std::shared_ptr<IPlayMode> &mode);

    void play() override;

//    std::vector<std::shared_ptr<IPlayable>>::iterator submembers() override;
//
//    std::vector<std::shared_ptr<IPlayable>>::iterator submembersEnd() override;

};


#endif //PLAYLIST_PLAYLIST_H
