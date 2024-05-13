#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getN(const char &c) {
        switch (c) {
            case '(':
                return 1;
            case ')':
                return 1001;
            case '[':
                return 2;
            case ']':
                return 1002;
            case '{':
                return 3;
            case '}':
                return 1003;
            default:
                return -1;
        }
    }
    bool isValid(string s) {
        stack<int> sta;
        for (auto c : s) {
            int t = getN(c);
            if (t < 1000) { sta.push(t); }
            else {
                if (sta.empty()) { return false; }
                if (sta.top() != t - 1000) { return false; }
                else { sta.pop(); }
            }
        }
        return sta.empty();
    }
};

int main() {
    Solution s;
    auto ans = s.isValid("()()()()()");
    cout << ans;
    return 0;
}
