#ifndef PLAYLIST_IPLAYABLE_H
#define PLAYLIST_IPLAYABLE_H

#include <string>
#include <utility>
#include <vector>
#include <memory>

class IPlayable {
private:
    virtual bool contains(const IPlayable *entity) const { return entity == this; };
public:
    //TODO boost range
    IPlayable() = default;

    virtual ~IPlayable() {};

    virtual void play() = 0;

    friend class Playlist;

//    virtual std::vector<std::shared_ptr<IPlayable>>::iterator submembers() { return it; };
//
//    virtual std::vector<std::shared_ptr<IPlayable>>::iterator submembersEnd() { return it; };
};


#endif //PLAYLIST_IPLAYABLE_H
