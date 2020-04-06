#include "MorseCodeConverter.h"
#include "myrandom.h"

#include <algorithm>
#include <sstream>

std::unordered_map<char, QString> MorseCodeConverter::morseCodes {
    { ':', "___..." }, { '8', "___.."   },
    { '0', "_____"  }, { 'Q', "__._"    },
    { 'A', "._"     }, { 'D', "_.."     },
    { 'O', "___"    }, { '_', "..__._"  },
    { 'N', "_."     }, { 'R', "._."     },
    { 'B', "_..."   }, { 'E', "."       },
    { 'S', "..."    }, { 'C', "_._."    },
    { '/', "_.._."  }, { 'P', ".__."    },
    { '(', "_.__."  }, { 'F', ".._."    },
    { 'G', "__."    }, { '.', "._._._"  },
    { 'T', "_"      }, { ')', "_.__._"  },
    { 'H', "...."   }, { 'Y', "_.__"    },
    { 'U', ".._"    }, { '9', "____."   },
    { 'K', "_._"    }, { 'I', ".."      },
    { 'V', "..._"   }, { 'J', ".___"    },
    { '"', "._.._." }, { '7', "__..."   },
    { 'X', "_.._"   }, { 'W', ".__"     },
    { '6', "_...."  }, { 'L', "._.."    },
    { '?', "..__.." }, { 'M', "__"      },
    { '-', "_...._" }, { 'Z', "__.."    },
    { '1', ".____"  }, { '2', "..___"   },
    { '!', "_._.__" }, { '3', "...__"   },
    { '@', ".__._." }, { '4', "...._"   },
    { '5', "....."  }, { '=', "_..._"   },
    { ',', "__..__" }, { '\'', ".____." },
    { '+', "._._."  }, { ';', "_._._."  }
};

QString MorseCodeConverter::TextToCode(const std::string &text) noexcept {
    QString converted {""};
    for (const auto &character : text) {
        if (isspace(character))
            converted.append("  ");

        if (auto found = std::find_if(morseCodes.begin(), morseCodes.end(),
                                      [&character](const auto &value) {
                                        return toupper(character) == value.first;
                                      });
            found != morseCodes.end())
            converted.append(found->second + "  ");
    }
    return converted;
}

auto splitString(const std::string &str) {
    std::vector<std::string> temporaryContainer;
    std::istringstream iss{ std::string(str) };

    std::copy(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{}, std::back_inserter(temporaryContainer));
    return temporaryContainer;
}

QString MorseCodeConverter::CodeToText(const std::string &codes) noexcept {
    QString converted {""};
    std::vector<std::string> vCodes = splitString(codes);
    //if substr of spaces is found - insert space in converted text mr. sherlock!
    for (const auto& code : vCodes) {
        if (auto found = std::find_if(morseCodes.begin(), morseCodes.end(),
                [&code](const auto& value) {
                    return QString::fromStdString(code) == value.second;
                });
            found != morseCodes.end())
            converted.append(found->first);
        //else
            //err
    }
    return converted;
}

QString MorseCodeConverter::getRandomCode() noexcept {
    const int random = random::number<int>(65, 90);
    return morseCodes[static_cast<char>(random)];
}
