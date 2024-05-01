#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void appendRNum(string &s, const char &c, int n) {
        for (int i = 0; i < n; i++) { s += c; }
    }
    string intToRoman(int num) {
        int n = num;
        string s;
        if (n / 1000 > 0) {
            appendRNum(s, 'M', n / 1000);
            n %= 1000;
        }
        if (n >= 900) {
            s += "CM";
            n -= 900;
        }
        if (n / 100 > 0) {
            int t = n / 100;
            n %= 100;
            if (t <= 3) { appendRNum(s, 'C', t); }
            else if (t == 4) { s += "CD"; }
            else { s += 'D'; appendRNum(s, 'C', t - 5); }
        }
        if (n >= 90) {
            s += "XC";
            n -= 90;
        }
        if (n / 10 > 0) {
            int t = n / 10;
            n %= 10;
            if (t <= 3) { appendRNum(s, 'X', t); }
            else if (t == 4) { s += "XL"; }
            else { s += 'L'; appendRNum(s, 'X', t - 5); }
        }
        if (n >= 9) {
            s += "IX";
            n -= 9;
        }
        if (n > 0) {
            int t = n;
            if (t <= 3) { appendRNum(s, 'I', t); }
            else if (t == 4) { s += "IV"; }
            else { s += 'V'; appendRNum(s, 'I', t - 5); }
        }
        return s;
    }
};

int main() {
    Solution s;
//    auto ans = s.intToRoman(1994);
    auto ans = s.intToRoman(58);
    printf("%s", ans.c_str());
    return 0;
}
