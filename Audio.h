#ifndef PLAYLIST_AUDIO_H
#define PLAYLIST_AUDIO_H

#include "Playable.h"
#include "IMedia.h"

class Audio : public IMedia {
private:
public:
    using IMedia::IMedia;
    ~Audio() = default;
    void play() override;
};


#endif //PLAYLIST_AUDIO_H
