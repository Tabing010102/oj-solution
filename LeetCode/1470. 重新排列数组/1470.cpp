#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
		vector<int> ans(2 * n);
		for (int i = 0; i < n; i++) {
			ans[i * 2] = nums[i];
			ans[i * 2 + 1] = nums[i + n];
		}
		return ans;
    }
};

int main() {
	vector<int> x = { 2,5,1,3,4,7 };
	Solution s;
	auto ans = s.shuffle(x, 3);
	for (auto it = ans.begin(); it != ans.end(); it++) {
		printf("%d ", *it);
	}
	printf("\n");
	return 0;
}
