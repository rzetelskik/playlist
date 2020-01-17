#ifndef PLAYLIST_VIDEO_H
#define PLAYLIST_VIDEO_H

#include "IMedia.h"

class Video : public IMedia {
public:
    explicit Video(const std::string &name) : IMedia(name) {};
    ~Video() override = default;
    void play() override;
};


#endif //PLAYLIST_VIDEO_H
