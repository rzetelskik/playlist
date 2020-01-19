#ifndef PLAYLIST_MEDIAFACTORY_H
#define PLAYLIST_MEDIAFACTORY_H

#include <iostream>
#include <map>
#include <functional>
#include "IMedia.h"
#include "Audio.h"
#include "Video.h"

class MediaFactory {
private:
    std::map<std::string, std::function<IMedia(std::map<std::string, std::string>, std::string)>> factories =
            {
                    {"audio", [](auto metaData, auto content) { return Audio(metaData, content); }},
                    {"video", [](auto metaData, auto content) { return Video(metaData, content);}}
            };
public:
    //TODO moze jednak jakas klasa na te argumenty wszystkie?
    IMedia createMedia(std::string type, std::map<std::string, std::string> metaData, std::string content);
};


#endif //PLAYLIST_MEDIAFACTORY_H
