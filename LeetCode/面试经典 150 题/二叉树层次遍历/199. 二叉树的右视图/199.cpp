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

const int MAXH = 100 + 10;

class Solution {
public:
    vector<int> v;
    void dfs(T *curr, int dep) {
        if (!curr) { return; }
        dfs(curr->right, dep + 1);
        dfs(curr->left, dep + 1);
        if (v[dep] == -1 ) { v[dep] = curr->val; }
    }
    vector<int> rightSideView(TreeNode* root) {
        v.clear();
        v.resize(MAXH);
        for (int i = 0; i < MAXH; i++) { v[i] = -1; }
        dfs(root, 0);
        vector<int> ans;
        for (int i = 0; i < MAXH; i++) {
            if (v[i] == -1) { break; }
            ans.push_back(v[i]);
        }
        return ans;
    }
};

int main() {
    Solution s;
//    T *x = new T(1,
//                new T(2,
//                    nullptr,
//                    new T(5)),
//                new T(3,
//                    nullptr,
//                    new T(4)));
    T *x = new T(1,
                new T(2,
                    new T(4),
                    nullptr),
                new T(3));
    auto ans = s.rightSideView(x);
    for (auto a : ans) { cout << a << ' '; }
    return 0;
}
