#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    	vector<vector<int>> ret;
    	vector<int> ph;
    	// ret.push_back(ph);
    	unordered_map<int, int> m;
		int gsSize = groupSizes.size();
		for (int i = 0; i < gsSize; i++) {
			int cntSize = groupSizes[i];
			if (!m[cntSize]) {
				ret.push_back(ph);
				int cntP = ret.size();
				m[cntSize] = cntP;
				ret[cntP - 1].push_back(i);
			} else {
				ret[m[cntSize] - 1].push_back(i);
			}
			if (ret[m[cntSize] - 1].size() == cntSize)
				m[cntSize] = 0;
		}
		return ret;
    }
};

int main() {
	Solution sol;
	int n;
	vector<int> d;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		d.push_back(t);
	}
	vector<vector<int>> s = sol.groupThePeople(d);
	for (int i = 0; i < s.size(); i++) {
		vector<int> &cnt = s[i];
		for (int j = 0; j < cnt.size(); j++) {
			cout << cnt[j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
