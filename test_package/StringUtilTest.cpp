#include "gmock/gmock.h"
#include "StringUtil.h"

using namespace std;
using namespace testing;
using namespace stringutil;

TEST(AString,AnswersHeadAsEmptyWhenEmpty)
{
    ASSERT_THAT(head(""),Eq(""));
}
TEST(AString,AnswersTailAsAllLettersAfterHead)
{
    ASSERT_THAT(tail("xyz"),Eq("yz"));
}
TEST(AString,AnswersTailAsEmptyWhenEmpty)
{
    ASSERT_THAT(tail(""),Eq(""));
}
TEST(AString,AnswersTailAsEmptyWhenContainsOnlyOneCharacter)
{
    ASSERT_THAT(tail("X"),Eq(""));
}