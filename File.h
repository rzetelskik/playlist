#ifndef PLAYLIST_FILE_H
#define PLAYLIST_FILE_H

#include <string>
#include <map>

using FileType = std::string;
using MetaData = std::map<std::string, std::string>;
using FileContent = std::string;
using FileData = std::pair<std::map<std::string, std::string>, std::string>;

class File {
private:
    FileType type;
    MetaData metaData;
    FileContent content;
    void inspect(const std::string &input) const;
    void deduceType(const std::string &input);
    void extractMetaData(const std::string &input);
    void extractContent(const std::string &input);
public:
    explicit File(const std::string &str);
    ~File() = default;
    [[nodiscard]] const FileType &getFileType() const;
    [[nodiscard]] const MetaData &getMetaData() const;
    [[nodiscard]] const FileContent &getFileContent() const;
};


#endif //PLAYLIST_FILE_H
