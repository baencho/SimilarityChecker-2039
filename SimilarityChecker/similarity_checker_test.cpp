#include "gmock/gmock.h"
#include "similarity_checker.cpp"

TEST(TS, TC1) {
	SimilarityChecker checker;
	string str1 = "ABC";
	string str2 = "ABC";
	int actual = checker.getLengthPoint(str1, str2);
	EXPECT_EQ(60, actual);

}
int main()
{
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}