#ifndef PLAYLIST_FILEPARSER_H
#define PLAYLIST_FILEPARSER_H

#include <iostream>
#include <map>

class FileParser {
public:
    void inspect(std::string input);

    std::string deduceType(std::string input);

    std::map<std::string, std::string>
    extractMetaData(std::string input); //TODO moze sharedPtr? (nie znam sie wiec jak na razie w return robi sie kopia)

    std::string extractContent(std::string input);
};

class InvalidFileFormatException : public std::exception {
};

class InvalidFileContentException : public std::exception {
};

#endif //PLAYLIST_FILEPARSER_H
