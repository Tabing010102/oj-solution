#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = n + m - 1;
        int i1 = m - 1, i2 = n - 1;
        while (i1 >= 0 || i2 >= 0) {
            if (i1 < 0) {
                for (int i = i2; i >= 0; i--) {
                    nums1[idx--] = nums2[i];
                }
                break;
            } else if (i2 < 0) {
                for (int i = i1; i >= 0; i--) {
                    nums1[idx--] = nums1[i];
                }
                break;
            }
            if (nums1[i1] > nums2[i2]) { nums1[idx--] = nums1[i1--]; }
            else { nums1[idx--] = nums2[i2--]; }
        }
    }
};

int main() {
    return 0;
}
