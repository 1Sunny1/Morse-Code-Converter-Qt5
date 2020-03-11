#ifndef MORSECODECONVERTER_H
#define MORSECODECONVERTER_H

#include <unordered_map>
#include <QString>
#include <string>

namespace Filter {
    inline std::string ExcludeSpecialCharacters(std::string &&sample) noexcept {
        sample.erase(std::remove_if(sample.begin(), sample.end(),
                                    [](const auto &character) {
                                      return character < 32 || character > 125;
                                    }), sample.end());
        sample.shrink_to_fit();
        return std::move(sample);
    }
}

class MorseCodeConverter final {
public:
    explicit                                        MorseCodeConverter() = delete;
    static QString                                  TextToCode(const std::string &) noexcept;
    static QString                                  getRandomCode() noexcept;

private:
    static std::unordered_map<char, QString>        morseCodes;
};

#endif // MORSECODECONVERTER_H
