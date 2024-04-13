#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int Ans = 0;
	int Dep = 0;
	int max(const int &a, const int &b) { return a > b ? a : b; }
	int dfs(vector<int>& x, int dep, int l) {
//		printf("d=%d, l=%d\n", dep, l);
		if (dep == Dep) return x[l - 1];
		int lD = dfs(x, dep + 1, l * 2);
		int rD = dfs(x, dep + 1, l * 2 + 1);
//		printf("lSum=%d, rSum=%d\n", lSum, rSum);
		Ans += abs(lD - rD);
		return max(lD, rD) + x[l - 1];
	}
    int minIncrements(int n, vector<int>& cost) {
		Dep = log2(n + 1);
		dfs(cost, 1, 1);
        return Ans;
    }
};

int main() {
//	vector<int> x = { 1, 5, 2, 2, 3, 3, 1 };
//	vector<int> x = { 5, 3, 3 };
	vector<int> x = { 764,1460,2664,764,2725,4556,5305,8829,5064,5929,7660,6321,4830,7055,3761 };
	Solution s;
//	auto ans = s.minIncrements(7, x);
//	auto ans = s.minIncrements(3, x);
	auto ans = s.minIncrements(15, x);
	cout << ans << endl;
	return 0;
}
