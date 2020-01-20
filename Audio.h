#ifndef PLAYLIST_AUDIO_H
#define PLAYLIST_AUDIO_H

#include "IMedia.h"

class Audio : public IMedia {
private:
public:
    explicit Audio(const std::string &name) : IMedia(name) {};
    ~Audio() = default;
    void play() override;
};


#endif //PLAYLIST_AUDIO_H
