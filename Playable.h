#ifndef PLAYLIST_PLAYABLE_H
#define PLAYLIST_PLAYABLE_H

#include <string>
#include <utility>

class Playable {
private:
//    const std::string name;
public:
//    explicit Playable(std::string name) : name(std::move(name)) {};
    virtual ~Playable() {};
    virtual void play() = 0;
};


#endif //PLAYLIST_PLAYABLE_H
