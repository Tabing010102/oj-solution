#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int min(const int &a, const int &b) { return a < b ? a : b; }
	int max(const int &a, const int &b) { return a > b ? a : b; }
    int minIncrements(int n, vector<int>& cost) {
//        unordered_map<int, int> dm;
		int ans = 0;
        for (int i = 2; i <= log2(n + 1); i++) {
        	int l = pow(2, i - 1), r = pow(2, i) - 1;
        	int cMax = cost[l];
        	for (int j = l; j <= r; j++)
        		cMax = max(cMax, cost[j - 1]);
        	for (int j = l; j <= r; j++) {
        		int d = cMax - cost[j - 1];
//        		if (d > 0) {
//        			if (dm.find(d) != dm.end()) dm[d]++;
//        			else dm[d] = 1;
//        		}
				ans += d;
        	}
        }
        return ans;
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
