#ifndef PLAYLIST_ODDEVENMODE_H
#define PLAYLIST_ODDEVENMODE_H

#include "IPlayMode.h"

class OddEvenMode : public IPlayMode {
private:
    void playEveryOther(size_t start, const std::vector<std::shared_ptr<IPlayable>> &medias);
public:
    OddEvenMode() = default;
    ~OddEvenMode() = default;
    void play(const std::vector<std::shared_ptr<IPlayable>> &medias) override;
};

std::shared_ptr<OddEvenMode> createOddEvenMode();

#endif //PLAYLIST_ODDEVENMODE_H
