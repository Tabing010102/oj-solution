// not accepted, 349 / 355
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
	bool DEBUG = true;
public:
    bool isMatch(string s, string p) {
    	if (DEBUG) printf("cnt s=%s, p=%s\n", s.c_str(), p.c_str());
		int sLen = s.size(), pLen = p.size();
		int sP = 0, pP = 0;
		while (pP < pLen) {
			if (sP >= sLen) {
				while (pP < pLen - 1 && p[pP + 1] == '*') pP += 2;
				return pP == pLen;
			}
			char cp = p[pP];
			if (pP < pLen - 1 && p[pP + 1] == '*') {
				pP++;
				char cpPriv = p[pP - 1];
				if (pP == pLen - 1) {
					while (sP < sLen && (cpPriv == '.' || s[sP] == cpPriv)) sP++;
					pP++;
					continue;
				}
				int osP = sP;
				int opP = pP;
				while (pP < pLen - 2 && p[pP + 2] == '*') pP += 2;
				char cpNext = p[pP + 1];
				pP = opP;
				while (sP < sLen && (cpPriv == '.' || s[sP] == cpPriv) &&
						(p[pP + 1] != '.' && cpNext != s[sP + 1] && sP < sLen - 1)) sP++;
				int sPL = sP;
				sP = osP;
				while (sP < sLen && (cpPriv == '.' || s[sP] == cpPriv)) sP++;
				int sPR = sP;
//				if (sPR == sLen) sPR--;
				if (sPL == sPR) sP = sPL;
				else {
					for (int i = sPR; i >= osP; i--)
						if (isMatch(s.substr(i), p.substr(pP + 1)) == true)
							return true;
					return false;
				}
				pP++;
				continue;
			}
			else if (cp == '.') {
				pP++; sP++; 
				continue;
			} else {
				if (s[sP] != cp) return false;
				pP++; sP++;
				continue;
			}
		}
		return sP >= sLen;
    }
};

int main() {
	Solution sol;
	string x, y;
	cin >> x >> y;
	cout << sol.isMatch(x, y);
}
