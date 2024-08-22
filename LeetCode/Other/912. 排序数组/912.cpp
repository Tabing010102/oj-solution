#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void qsort(vector<int> &d, int L, int R) {
        if (L >= R) { return; }
        int oL = L, oR = R;
        int pos = L + (R - L) * ((double)rand() / RAND_MAX);
        swap(d[pos], d[L]);
        int p = d[L];
        while (L < R) {
            while (L < R && d[R] > p) { R--; }
            if (L < R) { d[L++] = d[R]; }
            while (L < R && d[L] < p) { L++; }
            if (L < R) { d[R--] = d[L]; }
        }
        d[L] = p;
        qsort(d, oL, L - 1);
        qsort(d, L + 1, oR);
    }
    vector<int> sortArray(vector<int>& nums) {
        srand(time(NULL));
        qsort(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main() {
    return 0;
}