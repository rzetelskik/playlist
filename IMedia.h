#ifndef PLAYLIST_IMEDIA_H
#define PLAYLIST_IMEDIA_H

#include "IPlayable.h"
#include <map>
#include <utility>

using MetaData = std::map<std::string, std::string>;
using FileContent = std::string;

class IMedia : public IPlayable {
protected:
    const MetaData metaData;
    const FileContent content;
    bool contains(const IPlayable *entity) const { return this == entity; };
public:
    IMedia(MetaData metaData, FileContent content) :
        metaData(std::move(metaData)), content(std::move(content)) {};
    virtual ~IMedia() {};
};

#endif //PLAYLIST_IMEDIA_H
