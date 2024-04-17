#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    inline bool isDigit(const char c) { return c >= '0' && c <= '9'; }
    int getDigit(const string &s, int &idx) {
        int n = 0;
        while (isDigit(s[idx])) {
            n *= 10;
            n += s[idx] - '0';
            idx++;
        }
        return n;
    }
    void expand(const string &s, string &ans, int &i) {
        while (s[i] != ']') {
            const char c = s[i];
            if (isDigit(c)) {
                int n = getDigit(s, i);
                i++;
                int rsidx = ans.length();
                expand(s, ans, i);
                int reidx = ans.length() - 1;
                for (int j = 1; j < n; j++) { ans.append(ans.substr(rsidx, reidx - rsidx + 1)); }
            } else {
                ans += c;
            }
            i++;
        }    
    }
    string decodeString(string s) {
        string ans;
        ans.reserve(32768);
        string x = "1[" + s + "]";
        int idx = 2;
        expand(x, ans, idx);
        return ans;
    }
};

int main() {
//    string x = "3[a2[c]]";
    string x = "2[abc]3[cd]ef";
    Solution s;
    auto ans = s.decodeString(x);
    cout << ans << endl;
    return 0;
}
