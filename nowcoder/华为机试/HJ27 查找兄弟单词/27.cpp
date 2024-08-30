#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct SS {
    string s;
    int m[26];
    SS() { memset(m, 0, sizeof(m)); };
    SS(const string &s) {
        this->s = s;
        memset(m, 0, sizeof(m));
        for (const char &c : s) { m[c - 'a']++; }
    }
    bool operator == (const SS &rhs) const {
        for (int i = 0; i < 26; i++) if (m[i] != rhs.m[i]) { return false; }
        return true;
    }
};

int n;
vector<SS> d;
vector<string> vs;
string target;
int k;

int main() {
    cin >> n;
    string t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        d.push_back(SS(t));
    }
    cin >> target >> k;
    SS ts = SS(target);
    for (int i = 0; i < n; i++) {
        if (d[i] == ts && d[i].s != ts.s) {
            vs.push_back(d[i].s);
        }
    }
    sort(vs.begin(), vs.end());
    cout << vs.size() << endl;
    if (vs.size() >= k) { cout << vs[k - 1]; }
    return 0;
}
