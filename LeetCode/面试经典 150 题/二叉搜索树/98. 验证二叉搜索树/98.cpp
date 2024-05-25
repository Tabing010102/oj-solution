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
    T *last;
    bool ans;
    void dfs(T *curr) {
        if (!curr || !ans) { return; }
        dfs(curr->left);
        if (last && last->val >= curr->val) { ans = false; return; }
        last = curr;
        dfs(curr->right);
    }
    bool isValidBST(TreeNode* root) {
        last = nullptr;
        ans = true;
        dfs(root);
        return ans;
    }
};

int main() {
    Solution s;
    T *x = new T(1,
                new T(2,
                    new T(4),
                    nullptr),
                new T(3));
    return 0;
}
