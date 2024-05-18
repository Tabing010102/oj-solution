#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int readInt(const string &s, const int &n, int &p) {
        int tans = 0;
        while (p < n && s[p] >= '0' && s[p] <= '9') {
            tans *= 10;
            tans += s[p] - '0';
            p++;
        }
        p--;
        return tans;
    }
    int calc(int i1, int i2, char op) {
        switch (op) {
            case '+':
                return i1 + i2;
            case '-':
                return i1 - i2;
            case '*':
                return i1 * i2;
            case '/':
                return i1 / i2;
            default:
                return 0;
        }
    }
    int calculate(string s) {
        stack<int> ns;
        stack<char> os;
        int n = s.size();
        int p = 0;
        while (p < n && s[p] == ' ') { p++; }
        char last = 0;
        while (p < n) {
            if (s[p] >= '0' && s[p] <= '9') {
                int t = readInt(s, n, p);
//                printf("readInt = %d\n", t);
                ns.push(t);
            } else {
//                printf("readOp = %c\n", s[p]);
                if (s[p] == '-' && (last == 0 || last == '(')) {
                    ns.push(-1);
                    os.push('*');
                } else if (s[p] == '(') {
                    os.push('(');
                } else if (s[p] == '+' || s[p] == '-') {
                    while (!os.empty() && os.top() != '(') {
                        int i2 = ns.top(); ns.pop();
                        int i1 = ns.top(); ns.pop();
                        int t = calc(i1, i2, os.top()); os.pop();
                        ns.push(t);
                    }
                    os.push(s[p]);
                } else if (s[p] == '*' || s[p] == '/') {
                    while (!os.empty() && (os.top() == '*' || os.top() == '/')) {
                        int i2 = ns.top(); ns.pop();
                        int i1 = ns.top(); ns.pop();
                        int t = calc(i1, i2, os.top()); os.pop();
                        ns.push(t);
                    }
                    os.push(s[p]);
                } else if (s[p] == ')') {
                    while (os.top() != '(') {
                        int i2 = ns.top(); ns.pop();
                        int i1 = ns.top(); ns.pop();
//                        printf(") calc %d %c %d\n", i1, os.top(), i2);
                        int t = calc(i1, i2, os.top()); os.pop();
                        ns.push(t);
                    }
                    os.pop();
                } else {
                    return -1;
                }
            }
            last = s[p];
            p++;
            while (p < n && s[p] == ' ') { p++; }
        }
        while (!os.empty()) {
            int i2 = ns.top(); ns.pop();
            int i1 = ns.top(); ns.pop();
            int t = calc(i1, i2, os.top()); os.pop();
            ns.push(t);
        }
        return ns.top();
    }
};

int main() {
    Solution s;
//    auto ans = s.calculate("-(6 * (2 + 3 )* 8 + 5))");
//    auto ans = s.calculate("(1+(4+5+2)-3)+(6+8)");
//    auto ans = s.calculate(" 2-1 + 2 ");
    auto ans = s.calculate("1-(     -2)");
    cout << ans;
    return 0;
}
