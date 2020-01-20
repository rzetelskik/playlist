#ifndef PLAYLIST_IMEDIA_H
#define PLAYLIST_IMEDIA_H

#include "IPlayable.h"
#include <map>
#include <utility>

using MetaData = std::map<std::string, std::string>;
using Content = std::string;

class IMedia : public IPlayable {
protected:
    const MetaData metaData;
    const Content content;
public:
    IMedia(MetaData metaData, Content content) :
        metaData(std::move(metaData)), content(std::move(content)) {};
    virtual ~IMedia() {};
};


#endif //PLAYLIST_IMEDIA_H
