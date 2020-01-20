#ifndef PLAYLIST_IPLAYMODE_H
#define PLAYLIST_IPLAYMODE_H

#include "IPlayable.h"
#include <memory>
#include <vector>

class IPlayMode {
public:
    virtual void play(const std::vector<std::shared_ptr<IPlayable>> &medias) = 0;
};

#endif //PLAYLIST_IPLAYMODE_H
