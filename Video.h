#ifndef PLAYLIST_VIDEO_H
#define PLAYLIST_VIDEO_H

#include "IMedia.h"
#include <utility>

class Video : public IMedia {
private:
    FileContent decodeROT13(const FileContent &content);
public:
    Video(const MetaData &metaData, const FileContent &content);
    ~Video() override = default;
    void play() override;
};

#endif //PLAYLIST_VIDEO_H
