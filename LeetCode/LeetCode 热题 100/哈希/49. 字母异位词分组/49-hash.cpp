#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MOD = 1e9 + 7;

struct HS {
	int d[26];
	
	HS(const string &s) {
		memset(d, 0, sizeof(d));
		for (auto c : s) { d[c - 'a']++; }
	}
	
	bool operator == (const HS &o) const {
		for (int i = 0; i < 26; i++) {
			if (this->d[i] != o.d[i]) {
				return false;
			}
		}
		return true;
	}
};

namespace std {
	template<>
	struct hash<HS> {
		inline size_t operator() (const HS &hs) const {
			size_t h = 0;
			int p = 1;
			for (int i = 0; i < 26; i++) {
				h += (int)(((LL)hs.d[i] * p) % MOD);
				p = (int)(((LL)p * 26) % MOD);
			}
			return h;
		}
	};
};

unordered_map<HS, int> um;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		um.clear();
		vector<vector<string>> ans;
		int p = 0;
		for (auto s : strs) {
			HS hs(s);
			if (um.find(hs) != um.end()) {
				ans[um[hs]].push_back(s);
			} else {
				ans.push_back(vector<string>());
				ans[p].push_back(s);
				um[hs] = p++;
			}
		}
		return ans;
    }
};

int main() {
	Solution s;
	vector<string> a = {"eat", "tea", "tan", "ate", "nat", "bat"};
	auto ans = s.groupAnagrams(a);
	for (auto a : ans) {
		for (auto b : a) {
			cout << b << " ";
		}
		cout << endl;
	}
	return 0;
}
