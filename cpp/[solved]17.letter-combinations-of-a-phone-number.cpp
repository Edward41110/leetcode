#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		char last;
		int lastSize = 1;
		vector<string> res;
		for (int i = 0;i < digits.length();i++) {
			last = 0;
			int length = getLength(digits[i]);
			if (i == 0) {
				for (int j = 0;j < length;j++) {
					res.push_back("");
				}
				for (int j = 0;j < res.size();j++) {
					res[j] += last = getNext(digits[i], last);
				}
			}
			else {
				int size = res.size();
				for (int j = 0;j < length - 1;j++) {
					for (int k = 0;k < size;k++) {
						res.push_back(res[k]);
					}
				}
				for (int j = 0;j < length;j++) {
					last = getNext(digits[i], last);
					for (int k = 0;k < lastSize;k++) {
						res[j * lastSize + k] += last;
					}
				}
			}
			lastSize *= length;
		}
		return res;
	}
private:
	int getLength(char digit) {
		if (digit == '7' || digit == '9') return 4;
		else return 3;
	}
	char getNext(char digit) {
		int dig = digit - '2';
		if (dig < 5) return 'a' + 3 * dig;
		else if (dig == 5) return 'p';
		else if (dig == 6) return 't';
		else return 'w';
	}
	char getNext(char digit, char last) {
		if (last == 0) return getNext(digit);
		char lim = getNext(digit) + getLength(digit) - 1;
		if (last == lim)
			return last - getLength(digit) + 1;
		else
			return last + 1;
	}
};

int main()
{
	Solution s;
	vector<string> v = s.letterCombinations("23");
	vector<string>::iterator it;
	for (it = v.begin();it != v.end();it++)
		cout << *it << endl;
	system("pause");
	return 0;
}

