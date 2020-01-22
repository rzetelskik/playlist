#include "File.h"
#include "PlayerException.h"
#include <regex>

void File::inspect(const std::string &input) const {
    static const std::string fileTypeFormat = "(.*)";
    static const std::string metaDataFormat = "(\\|((.*):(.*)\\|)*)";
    static const std::string arbitraryFileContentFormat = "(.*)";
    static const std::string structuredFileContentFormat = "([[:alnum:][:blank:],\\.!\\?':;-]*)";
    static const std::regex fileRgx(fileTypeFormat + metaDataFormat + arbitraryFileContentFormat);
    static const std::regex fileAndContentRgx(fileTypeFormat + metaDataFormat + structuredFileContentFormat);
    std::smatch sm;

    if (!std::regex_match(input, fileRgx)) {
        throw CorruptFileException();
    }
    if (!std::regex_match(input, fileAndContentRgx)) {
        throw CorruptContentException();
    }
}

void File::deduceType(const std::string &input) {
    static const std::string fileTypeSearchFormat = "[^\\|]*(?=\\|)";
    static const std::regex fileTypeRgx(fileTypeSearchFormat);
    std::smatch typeMatch;
    std::regex_search(input, typeMatch, fileTypeRgx);

    type = typeMatch.str();
}

void File::extractMetaData(const std::string &input) {
    static const std::string dataFieldFormat = "\\|([^:]*):([^\\|]*)";
    static const std::regex dataFieldRgx(dataFieldFormat);
    std::string log = input;
    std::smatch dataMatch;

    while (std::regex_search(log, dataMatch, dataFieldRgx)) {
        std::string name = dataMatch.str(1);
        std::string value = dataMatch.str(2);
        if (name == "year" && !isNumber(value)) {
            throw InvalidYearException();
        }
        auto result = metaData.insert({name, value});
        if (!result.second) result.first->second = value;

        log = dataMatch.suffix();
    }
}

void File::extractContent(const std::string &input) {
    static const std::string contentSearchFormat = ".*\\|(.*)";
    static const std::regex contentSearchRgx(contentSearchFormat);
    std::smatch contentMatch;
    std::regex_search(input, contentMatch, contentSearchRgx);

    content = contentMatch.str(1);
}

File::File(const std::string &str) {
    inspect(str);
    deduceType(str);
    extractMetaData(str);
    extractContent(str);
}

const FileType &File::getFileType() const {
    return type;
}

const MetaData &File::getMetaData() const {
    return metaData;
}

const FileContent &File::getFileContent() const {
    return content;
}

bool File::isNumber(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
