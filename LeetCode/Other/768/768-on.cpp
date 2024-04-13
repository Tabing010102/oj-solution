#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000 + 10;

// preMax <= postMin ans++
class Solution {
private:
	int aSize;
	int postMin[MAXN], preMax[MAXN];
	void Init(const vector<int> &arr) {
		preMax[0] = arr[0];
		for (int i = 1; i < aSize; i++)
			preMax[i] = max(preMax[i-1], arr[i]);
		postMin[aSize - 1] = arr[aSize - 1];
		for (int i = aSize - 2; i >= 0; i--)
			postMin[i] = min(postMin[i+1], arr[i]);
	}
	bool CanSplit(int p) {
		int lMax = preMax[p];
		int rMin = postMin[p+1];
		return lMax <= rMin;
	}
public:
    int maxChunksToSorted(vector<int>& arr) {
    	int ans = 1;
    	aSize = arr.size();
    	if (aSize == 1) return 1;
    	Init(arr);
    	for (int p = 0; p < aSize; p++) {
    		if (CanSplit(p)) {
				ans++;
				// printf("p=%d\n", p);
			}
    	}
    	return ans;
    }
};

int main() {
	Solution sol;
	int n;
	vector<int> v = {5,4,3,2,1};
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	cout << sol.maxChunksToSorted(v);
}
