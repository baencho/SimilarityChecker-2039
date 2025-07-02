#include "gmock/gmock.h"
#include "similarity_checker.cpp"

class LengthCheckerFixture : public testing::Test {
public:
	SimilarityChecker checker;
	void checkLengthPoint(const string& str1, const string& str2, int expected) {
		int actual = checker.getLengthPoint(str1, str2);
		EXPECT_EQ(expected, actual);
	}
};

TEST_F(LengthCheckerFixture, TC1) {
	checkLengthPoint("ABC", "ABC", 60);
}

TEST_F(LengthCheckerFixture, TC2) {
	checkLengthPoint("ABC", "ABCDE", 36);
}

TEST_F(LengthCheckerFixture, TC3) {
	checkLengthPoint("NLKISGDLIE", "ABCDE", 30);
}

TEST_F(LengthCheckerFixture, EmptyString1) {
	try {
		checker.checkEmptyString("", "ABC");
		FAIL();
	}
	catch (std::exception& e) {
		// PASS
	}
}

TEST_F(LengthCheckerFixture, EmptyString2) {
	const int INVALID_POINT = 0;
	try {
		checkLengthPoint("", "ABC", INVALID_POINT);
		FAIL();
	}
	catch (std::exception& e) {
		// PASS
	}
}

int main()
{
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}