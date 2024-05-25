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

struct T2 {
    T *tp;
    int dep;
    T2(T *a, int b) : tp(a), dep(b) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<T2> q;
        q.push(T2(root, 1));
        vector<vector<int>> ans;
        while (!q.empty()) {
            T2 t = q.front(); q.pop();
            if (!t.tp) { continue; }
            while (ans.size() < t.dep) { ans.push_back(vector<int>()); }
            ans[t.dep - 1].push_back(t.tp->val);
            q.push(T2(t.tp->left, t.dep + 1));
            q.push(T2(t.tp->right, t.dep + 1));
        }
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
    auto ans = s.levelOrder(x);
    for (auto a : ans) {
        for (auto b : a) { cout << b << " "; }
        cout << endl;
    }
    return 0;
}
