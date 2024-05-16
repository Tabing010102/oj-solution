#include <bits/stdc++.h>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void dfs(TreeNode *cnt) {
        if (!cnt) { return; }
        dfs(cnt->left);
        dfs(cnt->right);
        TreeNode *t = cnt->left;
        cnt->left = cnt->right;
        cnt->right = t;
    }
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};

int main() {
    Solution s;
    return 0;
}
