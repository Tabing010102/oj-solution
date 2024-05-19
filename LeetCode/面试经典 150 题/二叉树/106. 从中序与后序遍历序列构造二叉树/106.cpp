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

const int MAXN = 3000 + 10;

class Solution {
public:
    int n;
    unordered_map<int, int> um;
    bool vis[MAXN];
    T* build(vector<int> &posto, int &p, vector<int> &io) {
        int cntv = posto[p--];
        vis[um[cntv]] = true;
        T *cnt = new T(cntv);
        for (int i = um[cntv] + 1; i < n && p >= 0; i++) {
            if (vis[i]) { break; }
            if (io[i] == posto[p]) {
                cnt->right = build(posto, p, io);
                break;
            }
        }
        for (int i = um[cntv] - 1; i >= 0 && p >= 0; i--) {
            if (vis[i]) { break; }
            if (io[i] == posto[p]) {
                cnt->left = build(posto, p, io);
                break;
            }
        }
        return cnt;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        n = inorder.size();
        um.clear();
        for (int i = 0; i < n; i++) { um[inorder[i]] = i; }
        memset(vis, 0, sizeof(vis));
        int p = n - 1;
        T *root = build(postorder, p, inorder);
        return root;
    }
};

int main() {
    Solution s;
    return 0;
}
