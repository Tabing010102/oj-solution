#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int N;
    vector<string> ans;
    void dfs(string &tans, int lCnt, int rCnt) {
        if (lCnt == N && rCnt == N) {
            ans.push_back(tans);
            return;
        }
        if (lCnt < N) {
            tans.push_back('(');
            dfs(tans, lCnt + 1, rCnt);
            tans.pop_back();
        }
        if (rCnt < N && lCnt > rCnt) {
            tans.push_back(')');
            dfs(tans, lCnt, rCnt + 1);
            tans.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        ans.clear();
        N = n;
        string tans = "";
        dfs(tans, 0, 0);
        return ans;
    }
};

int main() {
    vector<int> x = { 2,3,6,7 };
    Solution s;
    auto ans = s.generateParenthesis(3);
    for (auto x : ans) { cout << x << endl; }
    return 0;
}
