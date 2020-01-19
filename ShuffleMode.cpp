#include "ShuffleMode.h"

#include <numeric>
#include <algorithm>

void ShuffleMode::play(const std::vector<std::shared_ptr<Playable>> &medias) {
    std::vector<size_t> ivector(medias.size());
    std::iota(ivector.begin(), ivector.end(), 0);
    std::shuffle(ivector.begin(), ivector.end(), generator);

    for (auto i: ivector) {
        medias.at(i)->play();
    }
}

std::shared_ptr<ShuffleMode> createShuffleMode(int seed) {
    return std::make_shared<ShuffleMode>(seed);
}
