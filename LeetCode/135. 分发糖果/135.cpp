#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<int> ansv;
    int candy(vector<int>& ratings) {
    	int posCount = 1;
		int negCount = 1;
		int last = -1;
		ansv.clear();
		ansv.resize(ratings.size());
		for (int i = 0; i < ratings.size(); i++) {
			int x = ratings[i];
			if (last == -1) { last = x; ansv[i] = 0; continue; }
			if (x > last) {
				// continue pos
				if ((posCount == 1 && negCount == 1) || posCount > 1) { posCount++; ansv[i] = posCount - 1; }
				else {
					if (negCount - 1 > ansv[i - negCount]) ansv[i - negCount] = negCount - 1;
					for (int j = i, k = 0; j > i - negCount + 1; j--, k++) ansv[j] = k;
					negCount = 1; posCount = 2; ansv[i] = posCount - 1;
				}
			} else if (x == last) {
				if (posCount > 1) { posCount = 1; }
				else if (negCount > 1) {
					if (negCount - 1 > ansv[i - negCount]) ansv[i - negCount] = negCount - 1;
					for (int j = i - 1, k = 0; j > i - negCount; j--, k++) ansv[j] = k;
					negCount = 1;
				}
			} else {
				if ((posCount == 1 && negCount == 1) || negCount > 1) { negCount++; }
				else { posCount = 1; negCount = 2; }
			}
			last = x;
		}
		if (negCount > 1) {
			if (negCount - 1 > ansv[ratings.size() - negCount]) ansv[ratings.size() - negCount] = negCount - 1;
			for (int i = ratings.size() - 1, k = 0; i > ratings.size() - 1 - negCount + 1; i--, k++) ansv[i] = k;
		}
		int ans = 0;
		for (auto it = ansv.begin(); it != ansv.end(); it++) ans += *it;
		ans += ratings.size();
		return ans;
    }
};

int main() {
//	vector<int> x = { 1, 0, 2 };
//	vector<int> x = { 1, 2, 2 };
//	vector<int> x = { 1, 3, 2, 2, 1 };
	vector<int> x = { 1, 3, 4, 5, 2 };
	Solution s;
	auto ans = s.candy(x);
	cout << ans << endl;
	for (auto it = s.ansv.begin(); it != s.ansv.end(); it++) cout << *it << " ";
	cout << endl;
	return 0;
}
