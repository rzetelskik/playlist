#ifndef PLAYLIST_IPLAYABLE_H
#define PLAYLIST_IPLAYABLE_H

#include <string>
#include <utility>

class IPlayable {
public:
    //TODO boost range
    IPlayable() = default;
    virtual ~IPlayable() {};
    virtual void play() = 0;
};


#endif //PLAYLIST_IPLAYABLE_H
