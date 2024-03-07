#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

// (a * b) % m = ((a % m) * (b % m)) % m
// (a + b) % m = ((a % m) % (b % m)) % m
class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.size();
        int *d = new int[n];
        for (int i = 0; i < n; i++)
        	d[i] = word[i] - '0';
        int *dm = new int[n];
        dm[0] = d[0] % m;
        for (int i = 1; i < n; i++) {
        	int tm = dm[i - 1];
        	int pre = (int)(((LL)tm * (10 % m)) % m);
        	dm[i] = (int)(((LL)pre + d[i] % m) % m);
        }
        vector<int> ans(n);
//        bool zero = true;
        for (int i = 0; i < n; i++) {
//        	if (d[i] > 0) zero = false;
//        	if (zero) ans[i] = 0;
//        	else ans[i] = dm[i] == 0 ? 1 : 0;
			ans[i] = dm[i] == 0 ? 1 : 0;
        }
        delete [] d;
        delete [] dm;
    	return ans;
    }
};

int main() {
	Solution s;
//	auto ans = s.divisibilityArray("998244353", 3);
	auto ans = s.divisibilityArray("101010", 10);
	for (auto it = ans.begin(); it != ans.end(); it++)
		cout << *it;
	cout << endl;
	return 0;
}
