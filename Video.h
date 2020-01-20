#ifndef PLAYLIST_VIDEO_H
#define PLAYLIST_VIDEO_H

#include "IMedia.h"
#include <utility>

//TODO szyfrowanie
class Video : public IMedia {
public:
    Video(MetaData metaData, Content content) :
        IMedia(std::move(metaData), std::move(content)) {};
    ~Video() override = default;
    void play() override;
};

#endif //PLAYLIST_VIDEO_H
