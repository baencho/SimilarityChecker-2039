#include <string>
#include <iostream>

using std::string;

class SimilarityChecker {
public:
	int getLengthPoint(string str1, string str2) {
		if (str1.length() == str2.length()) return MAX_LENGTH_POINT;

		int diff = 0;
		int longerLength = 0;
		if (str1.length() > str2.length()) {
			diff = str1.length() - str2.length();
			longerLength = str1.length();
		}
		else {
			diff = str2.length() - str1.length();
			longerLength = str2.length();
		}
		double percentage = (double)(diff) / (double)(longerLength);

		double partialPoint = (1.0 - percentage) * 60.0;

		return (int)partialPoint;
	}

private:
	const int MAX_LENGTH_POINT = 60;
};