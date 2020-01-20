#ifndef PLAYLIST_AUDIO_H
#define PLAYLIST_AUDIO_H

#include "IPlayable.h"
#include "IMedia.h"

class Audio : public IMedia {
public:
    Audio(const MetaData &metaData, const FileContent &content) :
        IMedia(metaData, content) {};
    ~Audio() override = default;
    void play() override;
};


#endif //PLAYLIST_AUDIO_H
