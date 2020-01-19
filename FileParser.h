#ifndef PLAYLIST_FILEPARSER_H
#define PLAYLIST_FILEPARSER_H

#include <iostream>
#include <map>
#include "File.h"


class FileParser {
private:
    void inspect(const std::string &input);
    std::string deduceType(const std::string &input);
    std::map<std::string, std::string> extractMetaData(const std::string &input); //TODO moze sharedPtr? (nie znam sie wiec jak na razie w return robi sie kopia)
    std::string extractContent(const std::string &input);
public:
    FileParser() = default;
    ~FileParser() = default;
    std::tuple<std::string, std::map<std::string, std::string>, std::string> parseFile(const File &file);
};

class InvalidFileFormatException : public std::exception {
};

class InvalidFileContentException : public std::exception {
};

#endif //PLAYLIST_FILEPARSER_H
