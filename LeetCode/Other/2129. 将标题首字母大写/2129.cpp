#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	char toLower(const char &c) {
		if (c >= 'A' && c <= 'Z') return c - 'A' + 'a';
		else return c;
	}
	char toUpper(const char &c) {
		if (c >= 'a' && c <= 'z') return c - 'a' + 'A';
		else return c;
	}
    string capitalizeTitle(string title) {
        int len = title.size();
        int pos = 0;
        string ans;
        while (pos < len) {
        	int opos = pos;
        	while (pos < len && title[pos] != ' ') pos++;
        	if (pos - opos <= 2) {
        		for (int i = opos; i < pos; i++)
        			ans.push_back(toLower(title[i]));
        	} else {
        		ans.push_back(toUpper(title[opos]));
        		for (int i = opos + 1; i < pos; i++)
        			ans.push_back(toLower(title[i]));
        	}
        	if (pos < len) ans.push_back(' ');
        	pos++;
        }
        return ans;
    }
};

int main() {
	Solution s;
	auto ans = s.capitalizeTitle("capiTalIze tHe titLe");
	cout << ans << endl;
	return 0;
}
