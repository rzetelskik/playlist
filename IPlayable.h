#ifndef PLAYLIST_IPLAYABLE_H
#define PLAYLIST_IPLAYABLE_H

#include <string>
#include <utility>
#include <vector>
#include <memory>

class IPlayable {
public:
    virtual bool contains(const IPlayable *entity) const { return this == entity; };
    IPlayable() = default;
    virtual ~IPlayable() {};
    virtual void play() = 0;
};


#endif //PLAYLIST_IPLAYABLE_H
