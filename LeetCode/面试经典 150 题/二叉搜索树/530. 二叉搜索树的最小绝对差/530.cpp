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

const int INF = 1e5 + 10;

class Solution {
public:
    T *last;
    int ans;
    inline int min(const int &a, const int &b) { return a < b ? a : b; } 
    inline int abs(const int &a) { return a < 0 ? -a : a; }
    void dfs(T *curr) {
        if (!curr) { return; }
        dfs(curr->left);
        if (last) { ans = min(ans, abs(last->val - curr->val)); }
        last = curr;
        dfs(curr->right);
    }
    int getMinimumDifference(TreeNode* root) {
        ans = INF;
        last = nullptr;
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
    auto ans = s.getMinimumDifference(x);
    cout << ans;
    return 0;
}
