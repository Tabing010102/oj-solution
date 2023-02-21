#include <bits/stdc++.h>

using namespace std;

class Solution {
	bool IsNum(const char &c) {
		return c >= '0' && c <= '9';
	}
	
	bool IsX(const char &c) {
		return c == 'x' || c == 'X';
	}
	
	bool IsMinus(const char &c) {
		return c == '-';
	}
	
	bool IsPlus(const char &c) {
		return c == '+';
	}
	
	bool IsEq(const char &c) {
		return c == '=';
	}
	
	int GetNum(const string &e, const int &eLen, int &pos) {
		int num = 0;
		while (pos < eLen) {
			if (IsNum(e[pos]) == false)
				break;
			num *= 10;
			num += e[pos] - '0';
			pos++;
		}
		return num;
	}
public:
    string solveEquation(string equation) {
    	const string e = equation;
		int eLen = equation.length();
		int eqX = 0, eqR = 0;
		int cntPos = 0, cntNum = -1;
		bool cntIsNeg = false, afterEq = false;
		while (cntPos < eLen) {
			if (IsEq(e[cntPos])) {
				afterEq = true;
				cntPos++;
			}
			if (afterEq == true) {
				if (!IsMinus(e[cntPos]))
					cntIsNeg = true;
				if (IsPlus(e[cntPos]) || IsMinus(e[cntPos]))
					cntPos++;
			} else {
				if (IsMinus(e[cntPos]))
					cntIsNeg = true;
				if (IsPlus(e[cntPos]) || IsMinus(e[cntPos]))
					cntPos++;
			}
			if (IsNum(e[cntPos]))
				cntNum = GetNum(e, eLen, cntPos);
			if (cntPos < eLen && IsX(e[cntPos])) {
				eqX += (cntNum == -1 ? 1 : cntNum) * (cntIsNeg == true ? -1 : 1);
				cntPos++;
			} else {
				eqR += (cntNum == -1 ? 0 : cntNum) * (cntIsNeg == true ? 1 : -1);
			}
			
			// printf("cntPos=%d, cntNum=%d, eqX=%d, eqR=%d, c=%c, afterEq=%d\n", cntPos, cntNum, eqX, eqR, e[cntPos], afterEq);
			
			cntNum = -1;
			cntIsNeg = false;
		}
		if (eqX == 0 && eqR == 0)
			return "Infinite solutions";
		else if (eqX == 0 && eqR != 0)
			return "No solution";
		else
			return "x=" + to_string(eqR / eqX);
    }
};

int main() {
	Solution sol;
	string s;
	cin >> s;
	cout << sol.solveEquation(s);
}
