#include <bits/stdc++.h>

using namespace std;

const string M[] = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

class Solution {
public:
    vector<string> ans;
    void dfs(string &s, int sIdx, string &tans) {
        if (sIdx == s.size()) {
            ans.push_back(tans);
        } else {
            for (auto c : M[s[sIdx] - '0']) {
                tans.push_back(c);
                dfs(s, sIdx + 1, tans);
                tans.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) { return vector<string>(); }
        ans.clear();
        string s = "";
        dfs(digits, 0, s);
        return ans;
    }
};

int main() {
    Solution s;
    auto ans = s.letterCombinations("23");
    for (auto x : ans) { cout << x << " "; }
    return 0;
}
