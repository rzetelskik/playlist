#ifndef PLAYLIST_FILE_H
#define PLAYLIST_FILE_H

#include <string>

class File {
private:
    const std::string description;
public:
    explicit File(std::string str) : description(std::move(str)) {};
};


#endif //PLAYLIST_FILE_H
