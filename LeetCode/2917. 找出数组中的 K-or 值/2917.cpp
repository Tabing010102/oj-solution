#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int sd[31];
        sd[0] = 1;
        for (int i = 1; i < 31; i++) sd[i] = sd[i - 1] * 2;
		int ans = 0;
        for (int i = 0; i < 31; i++) {
        	int n = 0;
        	for (auto it = nums.begin(); it != nums.end(); it++)
        		if ((*it & sd[i]) > 0)
        			n++;
        	if (n >= k) ans += sd[i];
        }
        return ans;
    }
};

int main() {
	Solution s;
	vector<int> x = {7,12,9,8,9,15};
	auto ans = s.findKOr(x, 4);
	cout << ans << endl;
	return 0;
}
