#ifndef PLAYLIST_VIDEO_H
#define PLAYLIST_VIDEO_H

#include "IMedia.h"
#include <utility>

//TODO szyfrowanie
class Video : public IMedia {
private:
    FileContent decodeROT13(const FileContent &content);
public:
    Video(const MetaData &metaData, const FileContent &content) :
        IMedia(metaData, decodeROT13(content)) {};
    ~Video() override = default;
    void play() override;
};

#endif //PLAYLIST_VIDEO_H
