#ifndef MORSECODECONVERTER_H
#define MORSECODECONVERTER_H
#include <unordered_map>
#include <QString>
#include <string>

class MorseCodeConverter final {
public:
    explicit MorseCodeConverter() = delete;
    static QString TextToCode(const std::string &) noexcept;
    static std::string ExcludeSpecialCharacters(std::string &&) noexcept;
private:
    static std::unordered_map<char, QString> morseCodes;

};

#endif // MORSECODECONVERTER_H
