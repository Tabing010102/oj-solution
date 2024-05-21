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

const bool DEBUG = 1;

typedef TreeNode T;

class Solution {
public:
    void f2(T *&cnt) {
        if (cnt == nullptr) { return; }
        T *ccnt = cnt;
        T *rc = cnt->right;
        if (!ccnt->left && !ccnt->right) {
            if (DEBUG) { printf("leaf: %d\n", ccnt->val); }
            return;
        } else {
            if (cnt->left) {
                if (DEBUG) { printf("lc link: %d -> %d\n", cnt->val, cnt->left->val); }
                cnt->right = cnt->left;
                cnt = cnt->right;
                f2(cnt);
                // fix AddressSanitizer: heap-use-after-free
                ccnt->left = nullptr;
            }
            if (rc) {
                if (DEBUG) { printf("rc link: %d -> %d\n", cnt->val, rc->val); }
                cnt->right = rc;
                cnt = cnt->right;
                f2(cnt);
            }
        }
    }
    void flatten(TreeNode* root) {
        f2(root);
    }
};

int main() {
    Solution s;
    T *x = new T(1,
                new T(2,
                    new T(3),
                    new T(4)),
                new T(5,
                    nullptr,
                    new T(6)));
    s.flatten(x);
    T *a = x;
    while (a != nullptr) {
        if (a->left != nullptr) { printf("EEEEEEEEEEEEEEE\n"); }
        printf("%d ", a->val);
        a = a->right;
    }
    return 0;
}
