#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    inline void swap(int &a, int &b) {
        int t = a;
        a = b;
        b = t;
    }
    void reverse(vector<int>& d, int sp, int ep) {
        while (sp < ep) { swap(d[sp++], d[ep--]); }
    }
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k %= size;
        if (k == 0) { return; }
        reverse(nums, size - k, size - 1);
        reverse(nums, 0, size - 1);
        reverse(nums, k, size - 1);
    }
};

int main() {
    vector<int> x = {1,2,3,4,5,6,7};
    Solution s;
    s.rotate(x, 2);
    for (auto n : x) { printf("%d ", n); }
    return 0;
}
