//
// Created by bartosz on 1/19/20.
//

#ifndef PLAYLIST_IMEDIA_H
#define PLAYLIST_IMEDIA_H

#include <iostream>
#include <map>
#include "Playable.h"


class IMedia : public Playable { //TODO moze virtual inheritance tutaj?
protected:
    std::map<std::string, std::string> metaData;
    std::string content;
public:
    virtual void play();

    IMedia(std::map<std::string, std::string> metaData, std::string content) :
            metaData(metaData), content(content) {};
};


#endif //PLAYLIST_IMEDIA_H
