#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(vector<int> &d, int a) {
        int cnt = 0;
        for (auto it = d.begin(); it != d.end(); it++) {
            if (cnt >= a) { return true; }
            if (*it >= a) { cnt++; }
        }
        return cnt >= a;
    }
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int L = 0, R = n;
        while (L < R) {
            if (L == R - 1) { return check(citations, R) ? R : L; }
            int M = L + (R - L) / 2;
            if (check(citations, M)) { L = M; }
            else { R = M - 1; }
        }
        return L;
    }
};

int main() {
//    vector<int> x = {3,0,6,1,5};
//    vector<int> x = {1,3,1};
    vector<int> x = {1};
    Solution s;
    auto ans = s.hIndex(x);
    printf("%d ", ans);
    return 0;
}
