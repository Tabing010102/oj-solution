#include <bits/stdc++.h>

using namespace std;

const int INF = 1e4 + 10;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0, r = 0;
        int last = INF;
        int len = nums.size();
        while (r < len) {
            if (nums[r] != last) {
                last = nums[r];
                nums[l++] = nums[r++];
            } else {
                while (r < len && nums[r] == last) { r++; }
                last = nums[r - 1];
            }
        }
        return l;
    }
};

int main() {
    vector<int> x = {0,0,1,1,1,2,2,3,3,4};
    Solution s;
    auto a = s.removeDuplicates(x);
    for (int i = 0; i < a; i++) { printf("%d ", x[i]); }
    return 0;
}
