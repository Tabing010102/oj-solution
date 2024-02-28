#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int INF = 0x7fffffff;
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<vector<int>> ans;
        int lasti = INF;
        for (int i = 0; i < size - 2; i++) {
        	if (lasti == INF) lasti = nums[i];
        	else if (lasti == nums[i]) continue;
        	else lasti = nums[i];
        	int lastj = INF;
        	for (int j = i + 1; j < size - 1; j++) {
        		if (lastj == INF) lastj = nums[j];
        		else if (lastj == nums[j]) continue;
        		else lastj = nums[j];
        		int target = -(nums[i] + nums[j]);
        		auto it = upper_bound(nums.begin(), nums.end(), target);
        		if (it == nums.begin()) continue;
        		int pos;
        		if (it == nums.end()) pos = size;
				else pos = it - nums.begin();
        		if (nums[pos - 1] != target) continue;
        		pos--;
        		if (pos <= j) continue;
        		vector<int> tans = { nums[i], nums[j], nums[pos] };
        		ans.push_back(tans);
        	}
        }
        return ans;
    }
};

int main() {
//	vector<int> x = { -1,0,1,2,-1,-4 };
	vector<int> x = { 0,0,0 };
	Solution s;
	auto ans = s.threeSum(x);
	for (auto it = ans.begin(); it != ans.end(); it++) {
		for (auto it2 = it->begin(); it2 != it->end(); it2++)
			printf("%d ", *it2);
		printf("\n");
	}
	return 0;
}
