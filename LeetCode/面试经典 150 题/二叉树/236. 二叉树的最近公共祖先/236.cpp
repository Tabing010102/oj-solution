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
    T *ans;
    T *P, *Q;
    bool dfs(T *curr) {
        if (!curr) { return false; }
        if (ans) { return false; }
        bool lcb = dfs(curr->left);
        bool rcb = dfs(curr->right);
        if (ans) { return false; }
        bool ret;
        if (lcb && rcb) { ans = curr; ret = false; }
        else if ((curr == P || curr == Q) && (lcb || rcb)) { ans = curr; ret = false; }
        else if (curr == P || curr == Q) { ret = true; }
        else { ret = lcb || rcb; }
        return ret;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = nullptr;
        P = p; Q = q;
        dfs(root);
        return ans;
    }
};

int main() {
    Solution s;
    T *x = new T(-10,
                new T(9),
                new T(20,
                    new T(15),
                    new T(7)));
    return 0;
}
