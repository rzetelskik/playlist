#ifndef PLAYLIST_AUDIO_H
#define PLAYLIST_AUDIO_H

#include "IPlayable.h"
#include "IMedia.h"

class Audio : public IMedia {
public:
    Audio(MetaData metaData, Content content) :
        IMedia(std::move(metaData), std::move(content)) {};
    ~Audio() override = default;
    void play() override;
};


#endif //PLAYLIST_AUDIO_H
