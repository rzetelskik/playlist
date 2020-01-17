#ifndef PLAYLIST_SHUFFLEMODE_H
#define PLAYLIST_SHUFFLEMODE_H

#include "IPlayMode.h"
#include "IMedia.h"
#include <random>

class ShuffleMode : public IPlayMode {
private:
    std::default_random_engine generator;
public:
    explicit ShuffleMode(int seed) : generator(seed) {};
    ~ShuffleMode() = default;
    void play(const std::vector<std::shared_ptr<IMedia>> &medias) override;
};

std::shared_ptr<ShuffleMode> createShuffleMode(int seed);

#endif //PLAYLIST_SHUFFLEMODE_H
