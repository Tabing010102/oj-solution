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
    int ans;
    void dfs(TreeNode *cnt, int dep) {
        ans = max(ans, dep);
        if (cnt->left) { dfs(cnt->left, dep + 1); }
        if (cnt->right) { dfs(cnt->right, dep + 1); }
    }
    int maxDepth(TreeNode* root) {
        ans = 0;
        if (root) { dfs(root, 1); }
        return ans;
    }
};

int main() {
    Solution s;
    return 0;
}
