#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int p = n - 1;
        while (s[p] == ' ') { p--; }
        int ans = 0;
        while (p >= 0 && s[p] != ' ') { ans++; p--; }
        return ans;
    }
};

int main() {
    Solution s;
    auto ans = s.lengthOfLastWord("luffy is still joyboy");
    printf("%d", ans);
    return 0;
}
