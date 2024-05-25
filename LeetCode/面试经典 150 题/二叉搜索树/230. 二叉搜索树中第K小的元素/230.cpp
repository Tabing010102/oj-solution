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
    int K, cnt, ans;
    void dfs(T *curr) {
        if (!curr) { return; }
        dfs(curr->left);
        if (cnt == K) {
            ans = curr->val;
            cnt++;
        } else {
            cnt++;
            dfs(curr->right);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        K = k;
        cnt = 1;
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
