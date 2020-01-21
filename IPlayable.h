#ifndef PLAYLIST_IPLAYABLE_H
#define PLAYLIST_IPLAYABLE_H

#include <string>
#include <utility>
#include <vector>
#include <memory>

class IPlayable {
private:
    virtual bool contains(const IPlayable *entity) const = 0;
public:
    IPlayable() = default;
    virtual ~IPlayable() {};
    virtual void play() = 0;
    friend class Playlist;
};


#endif //PLAYLIST_IPLAYABLE_H
