class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> Map;
		vector<int>::iterator it;
		for(it = nums.begin();it != nums.end();it++) {
			if (Map.find(*it) != Map.end())
				return {Map.find(*it)->second, distance(nums.begin(), it);}
			Map[target - *it] = distance(nums.begin(), it);	
		}
		return {-1, -1};
	}
}; 
