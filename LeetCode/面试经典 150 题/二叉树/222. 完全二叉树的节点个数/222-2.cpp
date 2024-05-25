#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

typedef TreeNode T;

class Solution {
public:
    bool check(T *root, int dep, int idx) {
        T *curr = root;
        int currIdx = 1;
        for (int i = 0; i < dep; i++) {
            int depR = dep - i;
            int mul = pow(2, depR);
            int L = currIdx * mul, R = currIdx * mul + mul - 1;
            int M = L + (R - L) / 2;
            currIdx *= 2; 
            if (idx > M) { currIdx++; curr = curr->right; }
            else { curr = curr->left; }
        }
        return curr;
    }
    int countNodes(TreeNode* root) {
        if (!root) { return 0; }
        T *lc = root->left;
        T *rc = root->right;
        int n = 0;
        while (lc && rc) {
            n++;
            lc = lc->left;
            rc = rc->right;
        }
        if (!lc && !rc) { return (int)pow(2, n + 1) - 1; }
        else {
            // [L, R)
            int L = pow(2, n + 1);
            int R = pow(2, n + 2);
            while (L + 1 < R) {
                int M = L + (R - L) / 2;
                if (check(root, n + 1, M)) { L = M; }
                else { R = M; }
            }
            return L;
        }
    }
};

int main() {
    Solution s;
    T *x = new T(1,
                new T(2,
                    new T(4),
                    new T(5)),
                new T(3,
                    new T(6),
                    nullptr));
    auto ans = s.countNodes(x);
    cout << ans;
    return 0;
}
