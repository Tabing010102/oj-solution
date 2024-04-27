#include <bits/stdc++.h>

using namespace std;

const int INF = 2e4 + 10;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> ansv;
        ansv.resize(n);
        for (int i = 0; i < n; i++) { ansv[i] = 1; }
        int lastp = 0, last = -INF;
        for (int i = 0; i < n; i++) {
            int c = ratings[i];
            if (c > last) { last = c; }
            else {
                for (int j = lastp, k = 1; j < i; j++, k++) {
                    if (k < ansv[j]) { k = ansv[j]; }
                    else { ansv[j] = k; }
                }
                lastp = i;
                last = c;
            }
        }
        for (int j = lastp, k = 1; j < n; j++, k++) {
            if (k < ansv[j]) { k = ansv[j]; }
            else { ansv[j] = k; }
        }
        last = -INF;
        for (int i = n - 1; i >= 0; i--) {
            int c = ratings[i];
            if (c > last) { last = c; }
            else {
                for (int j = lastp, k = 1; j > i; j--, k++) {
                    if (k < ansv[j]) { k = ansv[j]; }
                    else { ansv[j] = k; }
                }
                lastp = i;
                last = c;
            }
        }
        for (int j = lastp, k = 1; j >= 0; j--, k++) {
            if (k < ansv[j]) { k = ansv[j]; }
            else { ansv[j] = k; }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) { ans += ansv[i]; }
        return ans;
    }
};

int main() {
//    vector<int> x = {1,0,2};
    vector<int> x = {1,2,2};
    Solution s;
    auto ans = s.candy(x);
    printf("%d ", ans);
    return 0;
}
