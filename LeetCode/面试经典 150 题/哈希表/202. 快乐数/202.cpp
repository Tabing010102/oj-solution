#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<int, int> m;
    int get(int d) {
        int t = 0;
        while (d) {
            t += (d % 10) * (d % 10);
            d /= 10;
        }
        return t;
    }
    bool isHappy(int n) {
        m.clear();
        while (1) {
            int t = get(n);
            if (t == 1) { return true; }
            else if (m.find(n) != m.end()) { return false; }
            else { m[n] = n; n = t; }
        }
        return false;
    }
};

int main() {
    Solution s;
    auto ans = s.isHappy(2);
    cout << ans << " ";
    return 0;
}
