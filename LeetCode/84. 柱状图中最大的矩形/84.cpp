#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int upd[MAXN];
int downd[MAXN];
// mupd[i] = max size from i -> ?
int mupd[MAXN];
// mdownd[i] = max size from ? -> i
int mdownd[MAXN];

class Solution {
public:
	int max(const int &a, const int &b) { return a > b ? a : b; }
    int largestRectangleArea(vector<int>& heights) {
    	vector<int> &d = heights;
		int n = d.size();
		upd[n - 1] = 1;
		downd[0] = 1;
		for (int i = 1; i < n; i++) {
			if (d[i] <= d[i - 1]) downd[i] = downd[i - 1] + 1;
			else downd[i] = 1;
		}
		for (int i = n - 2; i >= 0; i--) {
			if (d[i] <= d[i + 1]) upd[i] = upd[i + 1] + 1;
			else upd[i] = 1;
		}
		memset(mupd, 0, sizeof(int) * n);
		memset(mdownd, 0, sizeof(int) * n);
		mdownd[0] = d[0];
		for (int i = 1; i < n; i++) {
			if (downd[i] == 1) mdownd[i] = d[i];
			else mdownd[i] = max(mdownd[i - 1], d[i] * downd[i]);
		}
		mupd[n - 1] = d[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			if (upd[i] == 1) mupd[i] = d[i];
			else mupd[i] = max(mupd[i + 1], d[i] * upd[i]);
		}
		printf("upd: ");
		for (int i = 0; i < n; i++) printf("%d ", upd[i]); printf("\n");
		printf("mupd: ");
		for (int i = 0; i < n; i++) printf("%d ", mupd[i]); printf("\n");
		printf("downd: ");
		for (int i = 0; i < n; i++) printf("%d ", downd[i]); printf("\n");
		printf("mdownd: ");
		for (int i = 0; i < n; i++) printf("%d ", mdownd[i]); printf("\n");
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = max(ans, mupd[i]);
			ans = max(ans, mdownd[i]);
			ans = max(ans, d[i] * (upd[i] + downd[i] - 1));
		}
		return ans;
    }
};

int main() {
	Solution s;
//	vector<int> x = { 2,1,5,6,2,3 };
//	vector<int> x = { 2,4 };
	vector<int> x = { 4,2,0,3,2,4,3,4 };
	auto ans = s.largestRectangleArea(x);
	cout << ans << endl;
	return 0;
}
