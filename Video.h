#ifndef PLAYLIST_VIDEO_H
#define PLAYLIST_VIDEO_H

#include "IMedia.h"

class Video : public IMedia {
public:
    using IMedia::IMedia;
    ~Video() override = default;
    void play() override;
};


#endif //PLAYLIST_VIDEO_H
