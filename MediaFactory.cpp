#include <utility>

#include <utility>

//
// Created by bartosz on 1/17/20.
//

#include "MediaFactory.h"
#include "PlayerException.h"

IMedia MediaFactory::createMedia(std::string type, std::map<std::string, std::string> metaData, std::string content) {
    try {
        return factories.at(type)(std::move(metaData), std::move(content));
    } catch (std::out_of_range &) {
        throw UnsupportedTypeException();
    }
}
