#include <bits/stdc++.h>

using namespace std;

unordered_set<int> us;
unordered_set<int> us2;
unordered_map<int, int> um;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		us.clear();
		us2.clear();
		um.clear();
		int ans = 0;
		for (const int &a : nums) { us.insert(a); }
		for (const int &a : nums) {
			if (us2.find(a) != us2.end()) { continue; }
			int tans = 0;
			int c = a;
			while (us.find(c) != us.end()) {
				if (us2.find(c) != us2.end()) {
					if (um.find(c) != um.end()) {
						tans += um[c];
					}
					break;
				}
				if (us2.find(c) == us2.end()) { us2.insert(c); }
				c++;
				tans++;
			}
			um[a] = tans;
			ans = max(ans, tans);
		}
		return ans;
    }
};

int main() {
	Solution s;
//	vector<int> a = {100,4,200,1,3,2};
	vector<int> a = {0,3,7,2,5,8,4,6,0,1};
	auto ans = s.longestConsecutive(a);
	printf("%d\n", ans);
	return 0;
}
