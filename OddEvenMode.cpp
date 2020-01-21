#include "OddEvenMode.h"

void OddEvenMode::playEveryOther(size_t start, const std::vector<std::shared_ptr<IPlayable>> &medias) {
    for (size_t i = start; i < medias.size(); i+=2) {
        medias.at(i)->play();
    }
}

void OddEvenMode::play(const std::vector<std::shared_ptr<IPlayable>> &medias) {
    playEveryOther(1, medias);
    playEveryOther(0, medias);
}

std::shared_ptr<OddEvenMode> createOddEvenMode() {
    auto static oddEvenMode = std::make_shared<OddEvenMode>();
    return oddEvenMode;
}
