#ifndef MORSECODECONVERTER_H
#define MORSECODECONVERTER_H
#include <unordered_map>
#include <QString>

class MorseCodeConverter {
public:
    explicit MorseCodeConverter() = default;
    static QString TextToCode(const QString &);

private:
    static std::unordered_map<char, QString> morseCodes;

};

#endif // MORSECODECONVERTER_H
