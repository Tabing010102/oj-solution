#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
	bool IsAlph(const char &c) {
		return c >= 'a' && c <= 'z';
	}
	bool IsNum(const char &c) {
		return c >= '0' && c <= '9';
	}
public:
    string reformat(string s) {
		vector<char> va;
		vector<char> vn;
		int sLen = s.length();
		for (int i = 0; i < sLen; i++) {
			if (IsAlph(s[i])) va.push_back(s[i]);
			if (IsNum(s[i])) vn.push_back(s[i]);
		}
		int vaSize = va.size();
		int vnSize = vn.size();
		if (abs(vaSize - vnSize) > 1) return "";
		string ret = "";
		if (vaSize >= vnSize) {
			ret.push_back(va[0]);
			for (int i = 0; i < vnSize; i++) {
				ret.push_back(vn[i]);
				if (i+1 < vaSize) ret.push_back(va[i+1]);
			}
		} else {
			ret.push_back(vn[0]);
			for (int i = 0; i < vaSize; i++) {
				ret.push_back(va[i]);
				if (i+1 < vnSize) ret.push_back(vn[i+1]);
			}
		}
		return ret;
    }
};

int main() {
	Solution sol;
	string s;
	cin >> s;
	cout << sol.reformat(s) << endl;
	return 0;
}
