#ifndef PLAYLIST_FILE_H
#define PLAYLIST_FILE_H

#include <string>
#include <map>

class File {
private:
//    const std::string description;
    std::map<std::string, std::string> metaData;
    std::string type;
public:
    explicit File(std::string str) : description(std::move(str)) {};
};


#endif //PLAYLIST_FILE_H
