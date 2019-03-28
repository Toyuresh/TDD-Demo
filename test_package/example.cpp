#include <gmock/gmock.h>
#include "Soundex.h"

using namespace testing;

class SoundexEncoding: public Test
{
public:
    Soundex soundex;
};
TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
   ASSERT_THAT(soundex.encoded("A"), Eq("A000")); 
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
   ASSERT_THAT(soundex.encoded("I"), Eq("I000"));
}

TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits) {
   EXPECT_THAT(soundex.encoded("Ab"), Eq("A100"));
   EXPECT_THAT(soundex.encoded("Ac"), Eq("A200"));
   EXPECT_THAT(soundex.encoded("Ad"), Eq("A300"));
}

TEST_F(SoundexEncoding,ReplacesMultipleConsonatsWithDigits)
{
    ASSERT_THAT(soundex.encoded("Acdl"),Eq("A234"));
}

TEST_F(SoundexEncoding,LimitsLengthToFourCharaters)
{
    ASSERT_THAT(soundex.encoded("Dcdlb").length(),Eq(4u));
}

TEST_F(SoundexEncoding,UppercasesFirstLetter)
{
    ASSERT_THAT(soundex.encoded("abcd"),StartsWith("A"));
}

TEST_F(SoundexEncoding,IgnoresVowelLikeLetters)
{
    ASSERT_THAT(soundex.encoded("BaAeEiIoOuUhHyYcdl"),Eq("B234")); 
}

TEST_F(SoundexEncoding,IgnoresCaseWhenEncodingConsonants)
{
    ASSERT_THAT(soundex.encoded("BCDL"),Eq(soundex.encoded("Bcdl")));
}
TEST_F(SoundexEncoding,CombinesDuplicateCodeWhen2ndLetterDuplicates1st)
{
    ASSERT_THAT(soundex.encoded("Bbcd"),Eq("B230"));
}
TEST_F(SoundexEncoding,DoesNotCombineDuplicateEncodingsSeparatedByVowels)
{
    ASSERT_THAT(soundex.encoded("Jbob"),Eq("J110"));
}