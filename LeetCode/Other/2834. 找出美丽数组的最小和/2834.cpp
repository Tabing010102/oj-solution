#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MOD = 1e9 + 7;

class Solution {
public:
    int minimumPossibleSum(int n, int target) {
        unordered_set<int> dd;
        int ans = 0;
        int cnt = 1;
        for (int i = 0; i < n; i++) {
        	while (dd.find(cnt) != dd.end()) cnt++;
        	ans = (int)(((LL)ans + cnt) % MOD);
        	if (dd.find(target - cnt) == dd.end()) dd.insert(target - cnt);
        	cnt++;
        }
        return ans;
    }
};

int main() {
	Solution s;
	cout << s.minimumPossibleSum(2, 3) << endl;
	return 0;
}
