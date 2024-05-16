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

typedef TreeNode T; 

class Solution {
public:
    bool ans;
    void dfs(TreeNode *lt, TreeNode *rt) {
        if (!ans) { return; }
        if (!lt && !rt) { return; }
        if ((lt && !rt) || (!lt && rt)) { ans = false; return; }
        if (lt->val != rt->val) { ans = false; return; }
        dfs(lt->left, rt->right);
        dfs(lt->right, rt->left);
    }
    bool isSymmetric(TreeNode* root) {
        ans = true;
        if (root) { dfs(root->left, root->right); }
        return ans;
    }
};

int main() {
    Solution s;
    auto ans = s.isSymmetric(new T(1,
        new T(2,
            nullptr,
            new T(3)),
        new T(2,
            nullptr,
            new T(3))
        ));
    cout << ans << endl;
    return 0;
}
