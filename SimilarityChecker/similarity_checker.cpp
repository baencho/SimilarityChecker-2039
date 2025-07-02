#include <string>
#include <iostream>
#include <stdexcept>

using std::string;

class SimilarityChecker {
public:
	void checkEmptyString(const string& str1, const string& str2) {
		if (str1.length() == 0 || str2.length() == 0) {
			throw std::invalid_argument("Should not put empty strings as input");
		}
	}

	int getLengthPoint(const string& str1, const string& str2) {
		checkEmptyString(str1, str2);
		if (checkDoubleLength(str1, str2)) return MIN_LENGTH_POINT;
		if (str1.length() == str2.length()) return MAX_LENGTH_POINT;
		return getPartialPoint(str1, str2);
	}

private:
	const int MAX_LENGTH_POINT = 60;
	const int MIN_LENGTH_POINT = 0;

	int checkDoubleLength(const string& str1, const string& str2) {
		if (str1.length() > str2.length() * 2) return true;
		if (str2.length() > str1.length() * 2) return true;
		return false;
	}

	int getPartialPoint(const string& str1, const string& str2) {
		int diff = getStringLengthDiff(str1, str2);
		int longerLength = getLongerStringLength(str1, str2);

		double percentage = static_cast<double>(diff) / static_cast<double>(longerLength);
		double partialPoint = (1.0 - percentage) * 60.0;

		return static_cast<int>(partialPoint);
	}

	int getLongerStringLength(const string& str1, const string& str2) {
		if (str1.length() > str2.length()) {
			return str1.length();
		}
		return str2.length();
	}

	int getStringLengthDiff(const string& str1, const string& str2) {
		if (str1.length() > str2.length()) {
			return str1.length() - str2.length();
		}
		return str2.length() - str1.length();
	}
};