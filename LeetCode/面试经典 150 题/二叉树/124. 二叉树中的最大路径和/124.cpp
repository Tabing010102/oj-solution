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

const int INF = 1000 + 10;

typedef TreeNode T;

class Solution {
public:
    T *currRoot = nullptr;
    int ans = -INF;
    inline int max(const int &a, const int &b) { return a > b ? a : b; }
    int getTMax(T *curr) {
        ans = max(ans, curr->val);
        if (!curr->left && !curr->right) { return curr->val; }
        int lcv = 0, rcv = 0;
        if (curr->left) { lcv = getTMax(curr->left); }
        if (curr->right) { rcv = getTMax(curr->right); }
        lcv = max(0, lcv);
        rcv = max(0, rcv);
        int tans = curr->val + max(lcv, rcv);
        ans = max(ans, curr->val + lcv + rcv);
        return tans;
    }
    int maxPathSum(TreeNode* root) {
        ans = -INF;
        currRoot = root;
        getTMax(root);
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
    s.maxPathSum(x);
    return 0;
}
