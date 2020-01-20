#ifndef PLAYLIST_SEQUENCEMODE_H
#define PLAYLIST_SEQUENCEMODE_H

#include "IPlayMode.h"
#include "IPlayable.h"
#include <memory>
#include <vector>

class SequenceMode : public IPlayMode {
public:
    SequenceMode() = default;
    ~SequenceMode() = default;
    void play(const std::vector<std::shared_ptr<IPlayable>> &medias) override;
};

std::shared_ptr<SequenceMode> createSequenceMode();

#endif //PLAYLIST_SEQUENCEMODE_H
