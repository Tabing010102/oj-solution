#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MOD = 1e9 + 7;

class Solution {
public:
	int powMod(int x, int y, int z) {
	    if (y == 0) return 1 % z;
	    int half = powMod(x, y >> 1, z);
	    half = (half * half) % z;
	    if ((y & 1) == 0) {
	        return half;
	    } else {
	        return (half * (x % z)) % z;
	    }
	}
	LL getAll(const string &s1, const string &s2) {
		int ssize = s1.size();
		LL ans = 0;
		int b = 0;
		for (int i = ssize - 1; i >= 0; i--) {
			if (s2[i] - s1[i] - b < 0) {
				ans += (s2[i] - s1[i] - b + 26) * powMod(26, ssize - i - 1, MOD);
				b = 1; 
			} else {
				ans += (s2[i] - s1[i] - b) * powMod(26, ssize - i - 1, MOD);
				b = 0;
			}
			ans %= MOD;
		}
		return ans;
	}
	LL getWithEvil(const string &cs1, const string &cs2, int spos, const string &evil) {
		string s1 = cs1;
		string s2 = cs2;
		int ssize = s1.size();
		int esize = evil.size();
		for (int i = spos, j = 0; j < esize; i++, j++) {
			const char &ec = evil[j];
			if (s2[i] == s1[i] && s2[i] != ec) { return 0; }
			if (s2[i] > s1[i] && (s1[i] < ec || s2[i] > ec)) { return 0; }
			if (s2[i] < s1[i] && (ec > s1[i] && ec < s2[i])) { return 0; }
		}
		LL ans = 0;
		int b = 0;
		for (int i = spos, j = 0; j < esize; i++, j++) { s1[i]++; }
		for (int i = ssize - 1; i >= 0; i--) {
			if (s2[i] - s1[i] - b < 0) {
				ans += (s2[i] - s1[i] - b + 26) * powMod(26, ssize - i - 1, MOD);
				b = 1; 
			} else {
				ans += (s2[i] - s1[i] - b) * powMod(26, ssize - 1 - 1, MOD);
				b = 0;
			}
			ans %= MOD;
		}
		return ans;
	}
    int findGoodStrings(int n, string s1, string s2, string evil) {
		LL ans = getAll(s1, s2);
		for (int i = 0; i < s1.size() - evil.size(); i++) {
			LL en = getWithEvil(s1, s2, i, evil);
			ans -= en;
			ans += MOD;
			ans %= MOD;
		}
		return ans;
    }
};

int main() {
	Solution s;
	cout << s.findGoodStrings(2, "aa", "da", "b") << endl;
	return 0;
}
