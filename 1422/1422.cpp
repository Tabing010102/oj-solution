#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500 + 10;

class Solution {
private:
	int sLen;
	int pre0[MAXN], post1[MAXN];
	void Init(const string &s) {
		sLen = s.length();
		pre0[0] = pre0[sLen+1] = 0;
		post1[0] = post1[sLen+1] = 0;
		for (int i = 1; i <= sLen; i++)
			pre0[i] = pre0[i-1] + (s[i-1] == '0' ? 1 : 0);
		for (int i = sLen; i >= 1; i--)
			post1[i] = post1[i+1] + (s[i-1] == '1' ? 1 : 0);
	}
	int GetScore(int p) {
		return pre0[p] + post1[p + 1];
	}
public:
    int maxScore(string s) {
    	Init(s);
    	int ans = 0;
    	for (int i = 1; i < sLen; i++)
    		ans = max(ans, GetScore(i));
    	return ans;
    }
};

int main() {
	Solution sol;
	string s;
	cin >> s;
	cout << sol.maxScore(s);
}
