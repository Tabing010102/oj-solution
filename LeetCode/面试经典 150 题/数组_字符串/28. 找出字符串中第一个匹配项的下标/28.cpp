#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int p = haystack.find(needle);
        return p == haystack.npos ? -1 : p;
    }
};

int main() {
    Solution s;
    auto ans = s.strStr("sadbutsad", "sad");
    printf("%d", ans);
    return 0;
}
