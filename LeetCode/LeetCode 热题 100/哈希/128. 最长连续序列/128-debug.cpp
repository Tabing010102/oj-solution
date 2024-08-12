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
		vector<int>& d = nums;
		int ans = 0;
		for (const int &a : nums) { us.insert(a); }
		for (const int &a : nums) {
			if (us2.find(a) != us2.end()) {
				printf("us2 found %d, a continue\n", a);
				continue;
			}
			int tans = 0;
			int c = a;
			while (us.find(c) != us.end()) {
				if (us2.find(c) != us2.end()) {
					printf("us2 found %d, a2 break\n", c);
					if (um.find(c) != um.end()) {
						tans += um[c];
						printf("um found %d = %d, tans = %d break\n", c, um[c], tans);
					}
					break;
				}
				printf("iterating %d\n", c);
				if (us2.find(c) == us2.end()) {
					printf("us2 insert %d\n", c);
					us2.insert(c);
				}
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
	vector<int> a = {100,4,200,1,3,2};
//	vector<int> a = {0,3,7,2,5,8,4,6,0,1};
	auto ans = s.longestConsecutive(a);
	printf("%d\n", ans);
	return 0;
}
