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

const int MAXH = 200 + 10;

class BSTIterator {
public:
    int depth;
    T *lvT[MAXH];
    T *currNext;
    
    BSTIterator(TreeNode* root) {
        depth = 0;
        memset(lvT, 0, sizeof(lvT));
        currNext = root;
        while (currNext->left) {
            lvT[depth++] = currNext;
            currNext = currNext->left;
        }
    }
    
    int next() {
        int val = currNext->val;
        // lc
        if (lvT[depth] == nullptr && depth > 0 && lvT[depth - 1]->left == currNext) {
            currNext = lvT[depth - 1];
            depth--;
        }
        // mid
        else if (lvT[depth] == currNext) {
            if (currNext->right) {
                currNext = currNext->right;
                depth++;
                while (currNext->left) {
                    lvT[depth] = currNext;
                    currNext = currNext->left;
                }
            } else {
                while (depth > 0 && lvT[depth - 1]->right == currNext) {
                    currNext = lvT[depth - 1];
                    lvT[depth - 1] = nullptr;
                    depth--;
                }
                if (depth >= 0) {
                    currNext = lvT[depth];
                } else {
                    currNext = nullptr;
                }
            }
        }
        // rc
        else {
            while (depth > 0 && lvT[depth - 1]->right == currNext) {
                currNext = lvT[depth - 1];
                lvT[depth - 1] = nullptr;
                depth--;
            }
            if (depth >= 0) {
                currNext = lvT[depth];
            } else {
                currNext = nullptr;
            }
        }
        return val;
    }
    
    bool hasNext() {
        return currNext;
    }
};

int main() {
    T *x = new T(7,
        new T(3),
        new T(15,
            new T(9),
            new T(20)));
    BSTIterator b(x);
    cout << b.next() << endl;
    cout << b.next() << endl;
    cout << "b" << b.hasNext() << endl;
    cout << b.next() << endl;
    cout << "b" << b.hasNext() << endl;
    cout << b.next() << endl;
    cout << "b" << b.hasNext() << endl;
    cout << b.next() << endl;
    cout << "b" << b.hasNext() << endl;
    return 0;
}
