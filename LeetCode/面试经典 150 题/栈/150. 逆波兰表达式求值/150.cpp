#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getNum(const string &s) {
        int n = 0, p = 0;
        bool m = false;
        if (s[0] == '-') { p = 1; m = true; }
        while (p < s.size()) {
            n *= 10;
            n += s[p] - '0';
            p++;
        }
        if (m) { n = -n; }
        return n;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (auto st : tokens) {
            if (st.size() == 1) {
                if (st[0] >= '0' && st[1] <= '9') { s.push(getNum(st)); }
                else {
                    int i2 = s.top(); s.pop();
                    int i1 = s.top(); s.pop();
                    switch (st[0]) {
                        case '+':
                            s.push(i1 + i2);
                            break;
                        case '-':
                            s.push(i1 - i2);
                            break;
                        case '*':
                            s.push(i1 * i2);
                            break;
                        case '/':
                            s.push(i1 / i2);
                            break;
                        default:
                            break;
                    }
                }
            } else {
                s.push(getNum(st));
            }
        }
        return s.top();
    }
};

int main() {
    vector<string> x = { "4","13","5","/","+" };
    Solution s;
    s.evalRPN(x);
    return 0;
}
