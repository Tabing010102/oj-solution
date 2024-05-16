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
    bool ans;
    void dfs(TreeNode *pc, TreeNode *qc) {
        if (!ans) { return; }
        if (!pc && !qc) { return; }
        if ((pc && !qc) || (!pc && qc)) { ans = false; return; }
        if (pc->val != qc->val) { ans = false; return; }
        dfs(pc->left, qc->left);
        dfs(pc->right, qc->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        ans = true;
        dfs(p, q);
        return ans;
    }
};

int main() {
    Solution s;
    return 0;
}
