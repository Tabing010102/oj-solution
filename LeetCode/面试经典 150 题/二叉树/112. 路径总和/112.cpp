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
    bool ans = false;
    void find(T *curr, int target, int cnt) {
        if (ans) { return; }
        if (!curr->left && !curr->right && cnt == target) { ans = true; return; }
        if (curr->left) { find(curr->left, target, cnt + curr->left->val); }
        if (curr->right) { find(curr->right, target, cnt + curr->right->val); }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        ans = false;
        if (root) { find(root, targetSum, root->val); }
        return ans;
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

    return 0;
}
