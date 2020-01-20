#ifndef PLAYLIST_FILEPARSER_H
#define PLAYLIST_FILEPARSER_H

#include <iostream>
#include <map>
#include "File.h"

using FileType = std::string;
using MetaData = std::map<std::string, std::string>;
using FileContent = std::string;
using FileData = std::pair<std::map<std::string, std::string>, std::string>;
using ParsedFile = std::pair<FileType, FileData>;

class FileParser {
private:
    void inspect(const std::string &input) const;
    [[nodiscard]] FileType deduceType(const std::string &input) const;
    [[nodiscard]] MetaData extractMetaData(const std::string &input) const ; //TODO moze sharedPtr? (nie znam sie wiec jak na razie w return robi sie kopia)
    [[nodiscard]] FileContent extractContent(const std::string &input) const;
public:
    FileParser() = default;
    ~FileParser() = default;
    [[nodiscard]] ParsedFile parse(const File &file) const;
};

#endif //PLAYLIST_FILEPARSER_H
