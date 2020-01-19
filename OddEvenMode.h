#ifndef PLAYLIST_ODDEVENMODE_H
#define PLAYLIST_ODDEVENMODE_H

#include "IPlayMode.h"

class OddEvenMode : IPlayMode {
public:
    OddEvenMode() = default;
    ~OddEvenMode() = default;
    void play(const std::vector<std::shared_ptr<Playable>> &medias) override;
};

std::shared_ptr<OddEvenMode> createOddEvenMode();

#endif //PLAYLIST_ODDEVENMODE_H
