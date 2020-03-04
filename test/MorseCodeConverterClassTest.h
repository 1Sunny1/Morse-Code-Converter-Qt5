#ifndef MORSECODECONVERTERCLASSTEST_H
#define MORSECODECONVERTERCLASSTEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "..\src\MorseCodeConverter.h"

using namespace testing;

TEST(MorseCodeConverterTest, IsCharacterEqualToCode) {
    QString result = MorseCodeConverter::TextToCode("a");
    QString result2 = MorseCodeConverter::TextToCode("1");
    QString result3 = MorseCodeConverter::TextToCode("/");
    EXPECT_EQ(result, "._  ");
    EXPECT_EQ(result2, ".____  ");
    EXPECT_EQ(result3, "_.._.  ");
}

TEST(MorseCodeConverterTest, PassingEmptyStringReturnsEmptyString) {
    QString result = MorseCodeConverter::TextToCode("");
    EXPECT_EQ(result.isEmpty(), true);
}

TEST(MorseCodeConverterTest, PassingSpaceReturnsFourSpaces) {
    QString result = MorseCodeConverter::TextToCode(" ");
    EXPECT_EQ(result, "    ");
}

TEST(MorseCodeConverterTest, PassingExcludedCharacterReturnsEmptyString) {
    QString result = MorseCodeConverter::TextToCode("€");
    QString result2 = MorseCodeConverter::TextToCode("ę");
    QString result3 = MorseCodeConverter::TextToCode("▓");
    EXPECT_EQ(result.isEmpty(), true);
    EXPECT_EQ(result2.isEmpty(), true);
    EXPECT_EQ(result3.isEmpty(), true);
}

TEST(MorseCodeConverterTest, PassingSentenceReturnsProperCode) {
    QString result = MorseCodeConverter::TextToCode("A cat has nine lives.");
    QString result2 = MorseCodeConverter::TextToCode("Curiosity killed the cat.");
    QString result3 = MorseCodeConverter::TextToCode("Easy come, easy go.");
    EXPECT_EQ(result, "._      _._.  ._  _      ....  ._  ...      _.  ..  _.  .      ._..  ..  ..._  .  ...  ._._._  ");
    EXPECT_EQ(result2, "_._.  .._  ._.  ..  ___  ...  ..  _  _.__      _._  ..  ._..  ._..  .  _..      _  ....  .      _._.  ._  _  ._._._  ");
    EXPECT_EQ(result3, ".  ._  ...  _.__      _._.  ___  __  .  __..__      .  ._  ...  _.__      __.  ___  ._._._  ");

}

#endif // MORSECODECONVERTERCLASSTEST_H
