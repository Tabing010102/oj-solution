#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int SSL = 3;

int getCharType(const char &c) {
    if (c >= '0' && c <= '9') { return 0; }
    else if (c >= 'a' && c <= 'z') { return 1; }
    else if (c >= 'A' && c <= 'Z') { return 2; }
    else { return 3; }
}

bool hasCommonSubstr(const string &s) {
    int l = s.length();
    for (int i = 0; i <= l - SSL * 2; i++) {
        int ll = l - i;
        for (int j = SSL; j <= ll / 2; j++) {
            string ss = s.substr(i, j);
            if (s.find(ss, i + j) != string::npos) {
//                printf("i=%d, j=%d, s.find=%d, ss=%s\n", i, j, s.find(ss, i + j), ss.c_str());
                return true;
            }
        }
    }
    return false;
}

int main() {
    string s;
    int v[4], vt;
    while (cin >> s) {
        if (s.length() < 8) { cout << "NG" << endl; continue; }
        memset(v, 0, sizeof(v));
        vt = 0;
        for (const char &c : s) { v[getCharType(c)]++; }
        for (int i = 0; i < 4; i++) if (v[i]) { vt++; }
        if (vt < 3) { cout << "NG" << endl; continue; }
        if (hasCommonSubstr(s)) { cout << "NG" << endl; continue; }
        else { cout << "OK" << endl; continue; }
    }
    return 0;
}
