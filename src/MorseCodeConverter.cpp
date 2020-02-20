#include "MorseCodeConverter.h"
#include <algorithm>

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

std::string MorseCodeConverter::ExcludeSpecialCharacters(std::string &&sample) noexcept {
    sample.erase(std::remove_if(sample.begin(), sample.end(),
                                [](const auto &character) {
                                  return character < 33 || character > 125;
                                }), sample.end());
    sample.shrink_to_fit();
    return std::move(sample);
}

QString MorseCodeConverter::TextToCode(const std::string &text) noexcept {
    QString converted{""};
    for (const auto &character : text) {
        if (isspace(character))
            converted.append("    ");

        if (auto found = std::find_if(morseCodes.begin(), morseCodes.end(),
                                      [&character](const auto &value) {
                                        return toupper(character) == value.first;
                                      });
            found != morseCodes.end())
            converted.append(found->second + "  ");
    }
    return converted;
}
