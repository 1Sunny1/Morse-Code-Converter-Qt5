#ifndef TST_ISCHARACTEREQUALTOCODE_H
#define TST_ISCHARACTEREQUALTOCODE_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST(MorseCodeConverterTest, IsCharacterEqualToCode)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

#endif // TST_ISCHARACTEREQUALTOCODE_H
