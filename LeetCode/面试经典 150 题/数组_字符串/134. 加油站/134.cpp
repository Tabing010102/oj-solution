#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int ans = 0;
        int lgas, lcost;
        while (ans < n) {
            lgas = 0; lcost = 0;
            bool f = false;
            for (int i = ans, j = 0; j < n; i++, j++) {
                int cpos = i % n;
                lgas += gas[cpos];
                lcost += cost[cpos];
                if (lgas < lcost) { f = true; ans = i + 1; break; }
            }
            if (f) { continue; }
            else { return ans; }
        }
        return -1;
    }
};

int main() {
    vector<int> x = {1,2,3,4,5};
    vector<int> y = {3,4,5,1,3};
    Solution s;
    auto ans = s.canCompleteCircuit(x, y);
     printf("%d ", ans);
    return 0;
}
