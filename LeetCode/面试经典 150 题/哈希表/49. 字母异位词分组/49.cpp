#include <bits/stdc++.h>

using namespace std;

struct HS {
    int d[26];
    HS(const string &s) {
        memset(d, 0, sizeof(d));
        for (auto c : s) { d[c - 'a']++; }
    }
    bool operator < (const HS &rhs) const {
        for (int i = 0; i < 26; i++) {
            if (this->d[i] != rhs.d[i]) {
                return this->d[i] < rhs.d[i];
            }
        }
        return false;
    }
    bool operator == (const HS &rhs) const {
        for (int i = 0; i < 26; i++) {
            if (this->d[i] != rhs.d[i]) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<HS, int> ansm;
        for (auto s : strs) {
            HS cnt = HS(s);
            if (ansm.find(cnt) != ansm.end()) { ans[ansm[cnt]].push_back(s); }
            else {
                ansm[cnt] = ans.size();
                vector<string> t;
                t.push_back(s);
                ans.push_back(t);
            }
        }
        return ans;
    }
};

int main() {
    vector<string> x = {"badc", "baba"};
    Solution s;
    auto ans = s.groupAnagrams(x);
//    cout << ans;
    return 0;
}
