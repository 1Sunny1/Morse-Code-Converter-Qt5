#ifndef FILTERTEST_H
#define FILTERTEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "..\src\MorseCodeConverter.h"

using namespace testing;

TEST(FilterTest, IsFilterExcludingSpecialCharacters){
    std::string result = Filter::ExcludeSpecialCharacters("Whęat Yó€ou gońńnna €do?");
    std::string result2 = Filter::ExcludeSpecialCharacters("Numb3r5 4r3nt 3XCLUD3D!");
    std::string result3 = Filter::ExcludeSpecialCharacters("Ñ░«┴▌π÷√");
    EXPECT_EQ(result, "What You gonna do?");
    EXPECT_EQ(result2, "Numb3r5 4r3nt 3XCLUD3D!");
    EXPECT_EQ(result3.empty(), true);
}

#endif // FILTERTEST_H
