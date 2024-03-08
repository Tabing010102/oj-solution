#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MOD = 1e9 + 7;

class Solution {
public:
	int min(const int &a, const int &b) { return a < b ? a : b; }
    int minimumPossibleSum(int n, int target) {
    	int ans = 0; 
        int k1 = min(n, target / 2);
        ans += (int)(((LL)(1 + k1) * k1 / 2) % MOD);
        if (n > target / 2) {
	        int n2 = n - target / 2;
	        int k2 = target + n2 - 1;
	        ans += (int)(((((LL)target + k2) % MOD) * n2 / 2) % MOD);
	    }
        return ans;
    }
};

int main() {
	Solution s;
//	cout << s.minimumPossibleSum(2, 3) << endl;
	cout << s.minimumPossibleSum(13, 50) << endl;
	return 0;
}
