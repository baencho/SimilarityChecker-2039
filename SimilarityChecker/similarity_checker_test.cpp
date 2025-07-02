#include "gmock/gmock.h"
#include "similarity_checker.cpp"

class TCFixture : public testing::Test {
public:
	SimilarityChecker checker;
	void checkLengthPoint(const string& str1, const string& str2, int expected) {
		int actual = checker.getLengthPoint(str1, str2);
		EXPECT_EQ(expected, actual);
	}
};

TEST_F(TCFixture, TC1) {
	checkLengthPoint("ABC", "ABC", 60);
}

TEST_F(TCFixture, TC2) {
	checkLengthPoint("ABC", "ABCDE", 36);
}

TEST_F(TCFixture, TC3) {
	checkLengthPoint("NLKISGDLIE", "ABCDE", 30);
}

int main()
{
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}