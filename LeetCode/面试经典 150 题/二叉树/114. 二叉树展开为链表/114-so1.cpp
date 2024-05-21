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

const bool DEBUG = 1;

typedef TreeNode T;

class Solution {
public:
    void flatten(TreeNode* root) {
        T *curr = root;
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                T *next = curr->left;
                T *pre = next;
                while (pre->right != nullptr) { pre = pre->right; }
                pre->right = curr->right;
                curr->left = nullptr;
                curr->right = next;
            }
            curr = curr->right;
        }
    }
};

int main() {
    Solution s;
    T *x = new T(1,
                new T(2,
                    new T(3),
                    new T(4)),
                new T(5,
                    nullptr,
                    new T(6)));
    s.flatten(x);
    T *a = x;
    while (a != nullptr) {
        if (a->left != nullptr) { printf("EEEEEEEEEEEEEEE\n"); }
        printf("%d ", a->val);
        a = a->right;
    }
    return 0;
}
