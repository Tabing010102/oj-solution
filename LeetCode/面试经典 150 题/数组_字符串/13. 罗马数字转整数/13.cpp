#include <bits/stdc++.h>

using namespace std;

const unordered_map<char, int> s_cm = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

class Solution {
public:
    int n;
    int getNum(int &p, const string &s) {
        char cc = s[p];
        if (p == n - 1) { p++; return s_cm.at(cc); }
        char cn = s[p + 1];
        int ret;
        if (cc == 'I' && cn == 'V') { p += 2; ret = 4; }
        else if (cc == 'I' && cn == 'X') { p += 2; ret = 9; }
        else if (cc == 'X' && cn == 'L') { p += 2; ret = 40; }
        else if (cc == 'X' && cn == 'C') { p += 2; ret = 90; }
        else if (cc == 'C' && cn == 'D') { p += 2; ret = 400; }
        else if (cc == 'C' && cn == 'M') { p += 2; ret = 900; }
        else {
            ret = 0;
            while (p < n && s[p] == cc) { p++; ret += s_cm.at(cc); }
        }
        return ret;
    }
    int romanToInt(string s) {
        n = s.length();
        int p = 0;
        int ans = 0;
        while (p < n) {
            ans += getNum(p, s);
        }
        return ans;
    }
};

int main() {
//    string str = "LVIII";
//    string str = "MCMXCIV";
    string str = "DCXXI";
    Solution s;
    auto ans = s.romanToInt(str);
    printf("%d ", ans);
    return 0;
}
