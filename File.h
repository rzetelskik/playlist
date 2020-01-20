#ifndef PLAYLIST_FILE_H
#define PLAYLIST_FILE_H

#include <string>
#include <map>

class File {
private:
    const std::string description;
public:
    explicit File(std::string str) : description(std::move(str)) {};
    friend class FileParser;
};


#endif //PLAYLIST_FILE_H
