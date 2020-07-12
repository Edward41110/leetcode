#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
	string reverseOnlyLetters(string S) {
		stack<char> st;
		string::iterator it;
		for(it = S.begin();it != str.end();it++) {
			if ((*it >= 'A' && *it <= 'Z') || (*it >= 'a' && *it <= 'z')) {
				st.push(*it);
			}
		}
		for(it = S.begin();it != str.end();it++) {
			if ((*it >= 'A' && *it <= 'Z') || (*it >= 'a' && *it <= 'z')) {
				*it = st.top();
				st.pop();
			}
		}
		return S;
	}
};
