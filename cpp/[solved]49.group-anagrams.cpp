#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		int max = 0x7FFFFFFF;
		vector<vector<string>> res;
		int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101 };
		map<int, vector<string>> Map;
		map<int, vector<string>>::iterator it;
		for (int i = 0;i < strs.size();i++) {
			long long pro = 1;
			for (int j = 0;j < strs[i].size();j++) {
				pro *= primes[strs[i][j] - 'a'];
				if (pro > max) {
					pro %= max;
				}
			}
			it = Map.find(pro);
			if (it != Map.end()) {
				it->second.push_back(strs[i]);
			}
			else {
				Map[pro] = {strs[i]};
			}
		}
		map<int, vector<string>>::iterator i;
		for (i = Map.begin();i != Map.end();i++) {
			res.push_back(i->second);
		}
		return res;
	}
};

int main()
{
	Solution s;
	
	getchar();
	return 0;
}

