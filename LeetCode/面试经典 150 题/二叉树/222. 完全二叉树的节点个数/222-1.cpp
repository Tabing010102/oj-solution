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
    int getFBTH(T *curr) {
        T *lc = curr->left;
        T *rc = curr->right;
        int n = 0;
        while (lc && rc) {
            n++;
            lc = lc->left;
            rc = rc->right;
        }
        return (lc || rc) ? -1 : n;
    }
    void dfs(T *curr) {
        if (!curr) { return; }
        int t = getFBTH(curr);
        if (t == -1) {
            dfs(curr->left);
            dfs(curr->right);
            ans++;
        } else {
            ans += (int)pow(2, t + 1) - 1;
        }
    }
    int countNodes(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};

int main() {
    Solution s;
    T *x = new T(1,
                new T(1,
                    new T(1),
                    new T(1)),
                new T(1,
                    new T(1),
                    nullptr));
    auto ans = s.countNodes(x);
    cout << ans;
    return 0;
}
