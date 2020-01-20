#include "FileParser.h"
#include "PlayerException.h"
#include <regex>

void FileParser::inspect(const std::string &input) const {
    static const std::string fileTypeFormat = "(.*)";
    static const std::string metaDataFormat = "(\\|((.*):(.*)\\|)*)";
    static const std::string arbitraryFileContentFormat = "(.*)";
    static const std::string structuredFileContentFormat = "([[:alnum:][:blank:],\\.!\\?':;-]*)";
    static const std::regex fileRgx(fileTypeFormat + metaDataFormat + arbitraryFileContentFormat);
    static const std::regex fileAndContentRgx(fileTypeFormat + metaDataFormat + structuredFileContentFormat);
    std::smatch sm;

    //TODO unsupported type

    if (!std::regex_match(input, fileRgx)) {
        throw CorruptFileException();
    }
    if (!std::regex_match(input, fileAndContentRgx)) {
        throw CorruptContentException();
    }
}

FileType FileParser::deduceType(const std::string &input) const {
    static const std::string fileTypeSearchFormat = "[^\\|]*(?=\\|)";
    static const std::regex fileTypeRgx(fileTypeSearchFormat);
    std::smatch typeMatch;
    std::regex_search(input, typeMatch, fileTypeRgx);

    return typeMatch.str();
}


MetaData FileParser::extractMetaData(const std::string &input) const {
    std::map<std::string, std::string> dataMap;
    static const std::string dataFieldFormat = "\\|([^:]*):([^\\|]*)";
    static const std::regex dataFieldRgx(dataFieldFormat);
    std::string log = input;
    std::smatch dataMatch;

    while (std::regex_search(log, dataMatch, dataFieldRgx)) {
        std::string name = dataMatch.str(1);
        std::string value = dataMatch.str(2);
        dataMap.insert({name, value});
        log = dataMatch.suffix();
    }

    return dataMap;
}

FileContent FileParser::extractContent(const std::string &input) const {
    static const std::string contentSearchFormat = ".*\\|(.*)";
    static const std::regex contentSearchRgx(contentSearchFormat);
    std::smatch contentMatch;
    std::regex_search(input, contentMatch, contentSearchRgx);

    return contentMatch.str(1);
}

ParsedFile FileParser::parse(const File &file) const {
    inspect(file.description);
    auto type = deduceType(file.description);
    auto metaData = extractMetaData(file.description);
    auto content = extractContent(file.description);

    return std::make_pair(type, std::make_pair(metaData, content));
}

