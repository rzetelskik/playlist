#ifndef PLAYLIST_AUDIO_H
#define PLAYLIST_AUDIO_H

#include "IMedia.h"

class Audio : public IMedia {
private:
public:
    void play() override;
};


#endif //PLAYLIST_AUDIO_H
