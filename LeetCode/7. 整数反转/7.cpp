#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
	const int NMIN = 0x80000000;
	const int NMAX = 0x7fffffff;
public:
    int reverse(int x) {
        if (x == 0) return x;
        int ox = x;
        int len = 0;
        int xt = x;
        while (xt != 0) { xt /= 10; len++; }
        if (len >= 11) return 0;
        int p = 1; for (int i = 0; i < len-1; i++) p *= 10;
        int ans = 0;
        while (x != 0) {
        	int t = x % 10;
        	if ((t < -2 || t > 2) && p == 1000000000) return 0;
        	x /= 10;
        	if ((ox < 0 && NMIN - ans > t*p) ||
        		(ox >= 0 && NMAX - ans < t*p)) return 0;
        	ans += t * p;
        	p /= 10;
        }
        return ans;
    }
};

int main() {
	Solution sol;
	int x;
	cin >> x;
	cout << sol.reverse(x);
}
