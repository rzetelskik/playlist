#ifndef PLAYLIST_IMEDIA_H
#define PLAYLIST_IMEDIA_H

#include <string>
#include <utility>

class IMedia {
private:
    const std::string name;
public:
    explicit IMedia(std::string name) : name(std::move(name)) {};
    virtual ~IMedia() {};
    virtual void play() = 0;
};


#endif //PLAYLIST_IMEDIA_H
