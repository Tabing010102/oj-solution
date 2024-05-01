#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    inline bool isValid(const char &c) {
        return (c >= '0' && c <= '9')
            || (c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z');
    }
    inline char toLower(const char &c) {
        if (c >= 'A' && c <= 'Z') { return c - 'A' + 'a'; }
        else return c;
    }
    bool isPalindrome(string s) {
        int r = s.size() - 1;
        int l = 0;
        while (l < r) {
            while (l < r && !isValid(s[l])) { l++; }
            while (r > l && !isValid(s[r])) { r--; }
            if (l < r && toLower(s[l]) != toLower(s[r])) { return false; }
            l++; r--;
        }
        return true;
    }
};

int main() {
    Solution s;
    auto ans = s.isPalindrome("A man, a plan, a canal: Panama");
    printf("%d", ans);
    return 0;
}
