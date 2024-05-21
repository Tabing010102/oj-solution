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
    int ans = 0;
    void dfs(T *curr, int cnt) {
        if (!curr->left && !curr->right) { ans += cnt; return; }
        if (curr->left) { dfs(curr->left, cnt * 10 + curr->left->val); }
        if (curr->right) { dfs(curr->right, cnt * 10 + curr->right->val); }
    }
    int sumNumbers(TreeNode* root) {
        ans = 0;
        if (root) { dfs(root, root->val); }
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
