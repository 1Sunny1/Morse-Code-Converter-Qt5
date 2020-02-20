#ifndef MORSECODECONVERTER_H
#define MORSECODECONVERTER_H
#include <unordered_map>
#include <QString>
#include <string>

class MorseCodeConverter {
public:
    explicit MorseCodeConverter() = default;
    static QString TextToCode(const std::string &);
    static std::string ExcludeSpecialCharacters(std::string &&);
private:
    static std::unordered_map<char, QString> morseCodes;

};

#endif // MORSECODECONVERTER_H
