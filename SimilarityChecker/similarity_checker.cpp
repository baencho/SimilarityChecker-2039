#include <string>
using std::string;

class SimilarityChecker {
public:
	int getLengthPoint(string str1, string str2) {
		if (str1.length() == str2.length()) return MAX_LENGTH_POINT;
	}

private:
	const int MAX_LENGTH_POINT = 60;
};