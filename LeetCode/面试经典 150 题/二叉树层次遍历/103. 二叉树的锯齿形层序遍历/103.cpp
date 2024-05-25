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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        deque<T2> q;
        q.push_back(T2(root, 1));
        vector<vector<int>> ans;
        if (!root) { return ans; }
        int lastOrder = -1;
        while (!q.empty()) {
            deque<T2> q2 = q;
            q.clear();
            if (q2.empty()) { continue; }
            while (ans.size() < q2.front().dep) { ans.push_back(vector<int>()); }
            if (lastOrder == -1) {
                while (!q2.empty()) {
                    T2 t2 = q2.front(); q2.pop_front();
                    ans[t2.dep - 1].push_back(t2.tp->val);
                    if (t2.tp->left) { q.push_back(T2(t2.tp->left, t2.dep + 1)); }
                    if (t2.tp->right) { q.push_back(T2(t2.tp->right, t2.dep + 1)); }
                }
            } else {
                while (!q2.empty()) {
                    T2 t2 = q2.back(); q2.pop_back();
                    ans[t2.dep - 1].push_back(t2.tp->val);
                    if (t2.tp->right) { q.push_front(T2(t2.tp->right, t2.dep + 1)); }
                    if (t2.tp->left) { q.push_front(T2(t2.tp->left, t2.dep + 1)); }
                }
            }
            lastOrder *= -1;
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
    auto ans = s.zigzagLevelOrder(x);
    for (auto a : ans) {
        for (auto b : a) { cout << b << " "; }
        cout << endl;
    }
    return 0;
}
