#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ri = nums.size() - 1;
        while (ri >= 0 && nums[ri] == val) { ri--; }
        int li = 0;
        while (li < ri) {
            if (nums[li] != val) { li++; }
            else {
                nums[li] = nums[ri--];
                while (ri >= li && nums[ri] == val) { ri--; }
                li++;
            }
        }
        return li;
    }
};

int main() {
    vector<int> x = {0,1,2,2,3,0,4,2};
    Solution s;
    s.removeElement(x, 2);
    return 0;
}
