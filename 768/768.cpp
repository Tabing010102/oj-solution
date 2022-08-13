#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000 + 10;
const int INF = 100000001;

// always find min value, split left side, then repeat the proc
class Solution {
private:
	int aSize;
	int htMin[MAXN], htMax[MAXN];
	int Lowbit(int x) {
		return x & (-x);
	}
	void UpdateMin(int p, int v) {
		int lp;
		while (p <= aSize) {
			htMin[p] = v;
			lp = Lowbit(p);
			for (int i = 1; i < lp; i <<= 1)
				htMin[p] = min(htMin[p], htMin[p-i]);
			p += Lowbit(p);
		}
	}
	void InitMin(const vector<int> &arr) {
		memset(htMin, 0, sizeof(htMin));
		int p = 1;
		for (auto it = arr.begin(); it != arr.end(); it++) {
			UpdateMin(p, *it);
			p++;
		}
	}
	int QueryMin(int l, int r, const vector<int> &arr) {
		int ret = INF;
		while (r >= l) {
			// printf("q l=%d, r=%d, ret=%d\n", l, r, ret);
			ret = min(arr[r-1], ret);
			r--;
			for (; r - Lowbit(r) >= l; r -= Lowbit(r))
				ret = min(htMin[r], ret);
		}
		return ret;
	}
	void UpdateMax(int p, int v) {
		int lp;
		while (p <= aSize) {
			htMax[p] = v;
			lp = Lowbit(p);
			for (int i = 1; i < lp; i <<= 1)
				htMax[p] = max(htMax[p], htMax[p-i]);
			p += Lowbit(p);
		}
	}
	void InitMax(const vector<int> &arr) {
		memset(htMax, 0, sizeof(htMax));
		int p = 1;
		for (auto it = arr.begin(); it != arr.end(); it++) {
			UpdateMax(p, *it);
			p++;
		}
	}
	int QueryMax(int l, int r, const vector<int> &arr) {
		int ret = 0;
		while (r >= l) {
			// printf("q l=%d, r=%d, ret=%d\n", l, r, ret);
			ret = max(arr[r-1], ret);
			r--;
			for (; r - Lowbit(r) >= l; r -= Lowbit(r))
				ret = max(htMax[r], ret);
		}
		return ret;
	}
	bool CanSplit(int p, const vector<int> &arr) {
		int lMax = QueryMax(1, p, arr);
		int rMin = QueryMin(p+1, aSize, arr);
		return lMax <= rMin;
	}
public:
    int maxChunksToSorted(vector<int>& arr) {
    	int ans = 0;
    	aSize = arr.size();
    	InitMin(arr);
    	InitMax(arr);
    	int p = 1;
    	while (p <= aSize) {
    		if (CanSplit(p, arr)) {
				ans++;
				//printf("p=%d, ans=%d\n", p, ans);
			}
			p++;
    	}
    	return ans;
    }
};

int main() {
	Solution sol;
	int n;
	vector<int> v = {8,18,3,5,3,6,9,16,4,11,22,32,23,24,30,29,35,22,24,33};
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	cout << sol.maxChunksToSorted(v);
}
