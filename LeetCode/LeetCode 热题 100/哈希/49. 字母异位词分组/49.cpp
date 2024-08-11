#include <bits/stdc++.h>

using namespace std;

struct Ft {
    int d[26];
    bool operator < (const Ft &rhs) const {
        for (int i = 0; i < 26; i++) {
            if (this->d[i] != rhs.d[i]) {
                return this->d[i] < rhs.d[i];
            }
        }
        return this->d[25] < rhs.d[25];
    }
    bool operator == (const Ft &rhs) const {
        for (int i = 0; i < 26; i++) {
            if (this->d[i] != rhs.d[i]) {
                return false;
            }
        }
        return true;
    }
    
    Ft(const string s) {
        memset(d, 0, sizeof(d));
        for (int i = 0; i < s.length(); i++) {
            d[s[i] - 'a']++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<Ft, int> umIdx;
        vector<vector<string>> ans;
        int idx = 0;
        for (auto it = strs.begin(); it != strs.end(); it++) {
            string &s = *it;
            Ft f = Ft(s);
            if (umIdx.find(f) != umIdx.end()) {
                ans[umIdx[f]].push_back(s);
            } else {
                vector<string> t;
                t.push_back(s);
                ans.push_back(t);
                umIdx[f] = idx;
                idx++;
            }
        }
        return ans;
    }
};

int main() {
    vector<string> x = { "eat","tea","tan","ate","nat","bat" };
    Solution s;
    auto ans = s.groupAnagrams(x);
    for (auto v : ans) {
        for (auto s : v) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}
