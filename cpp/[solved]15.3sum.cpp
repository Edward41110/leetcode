#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size() < 3) return res;
		sort(nums.begin(), nums.end());
		for (int i = 0;i < nums.size() - 2;i++) {
			if (nums[i] > 0 || nums[i] + nums[i + 1] + nums[i + 2] > 0) break;
			int left = i + 1;
			int right = nums.size() - 1;
			while (left < right) {
				if ((i != 0 && (nums[i] == nums[i - 1])) || (nums[i] + nums[right - 1] + nums[right] < 0)) break;
				if (left != i + 1 && nums[left] == nums[left - 1]) {
					left++;
					continue;
				}
				if (right != nums.size() - 1 && nums[right] == nums[right + 1]) {
					right--;
					continue;
				}
				int sum = nums[i] + nums[left] + nums[right];
				if (sum == 0) {
					res.push_back({ nums[i], nums[left], nums[right] });
					left++;
				}
				else if (sum < 0)
					left++;
				else
					right--;
			}
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<int> v;
	v.push_back(0);
	v.push_back(0);
	v.push_back(0);
	vector<vector<int>> res = s.threeSum(v);
	
	for (vector<vector<int>>::iterator it1 = res.begin();it1 != res.end();it1++) {
		for (vector<int>::iterator it2 = res.at(distance(res.begin(), it1)).begin();it2 != res.at(distance(res.begin(), it1)).end();it2++)
			cout << *it2 << "\t";
		cout << endl;
	}
	system("pause");
	return 0;
}
