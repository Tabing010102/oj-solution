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

const int MAXN = 1e4 + 10;

class Solution {
public:
    double s[MAXN];
    int n[MAXN];
    void dfs(T *curr, int dep) {
        if (!curr) { return; }
        n[dep]++;
        s[dep] += curr->val;
        dfs(curr->left, dep + 1);
        dfs(curr->right, dep + 1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        memset(s, 0, sizeof(s));
        dfs(root, 0);
        vector<double> ans;
        for (int i = 0; i < MAXN; i++) {
            if (!n[i]) { break; }
            ans.push_back(s[i] / n[i]);
        }
        return ans;
    }
};

int main() {
    Solution s;
    T *x = new T(3,
                new T(9),
                new T(20,
                    new T(15),
                    new T(7)));
    auto ans = s.averageOfLevels(x);
    for (auto a : ans) { cout << a << " "; }
    return 0;
}
