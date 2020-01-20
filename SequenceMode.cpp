#include "SequenceMode.h"
#include <memory>

void SequenceMode::play(const std::vector<std::shared_ptr<IPlayable>> &medias) {
    for (auto const &it: medias) {
        it->play();
    }
}

std::shared_ptr<SequenceMode> createSequenceMode() {
    return std::make_shared<SequenceMode>();
};
