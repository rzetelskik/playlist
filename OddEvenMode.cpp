#include "OddEvenMode.h"

//TODO jakos ladniej moze
void OddEvenMode::play(const std::vector<std::shared_ptr<IPlayable>> &medias) {
    for (size_t i = 1; i < medias.size(); i+=2) {
        medias.at(i)->play();
    }

    for (size_t i = 0; i < medias.size(); i+=2) {
        medias.at(i)->play();
    }
}

std::shared_ptr<OddEvenMode> createOddEvenMode() {
    return std::make_shared<OddEvenMode>();
}
