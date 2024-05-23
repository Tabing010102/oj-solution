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
    stack<T *> s;
    T *curr;
    
    BSTIterator(TreeNode* root) {
        curr = root;
    }
    
    int next() {
        while (curr) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        int ret = curr->val;
        curr = curr->right;
        return ret;
    }
    
    bool hasNext() {
        return curr || !s.empty();
    }
};

int main() {
//    T *x = new T(7,
//        new T(3),
//        new T(15,
//            new T(9),
//            new T(20)));
//    BSTIterator b(x);
//    cout << b.next() << endl;
//    cout << b.next() << endl;
//    cout << "b" << b.hasNext() << endl;
//    cout << b.next() << endl;
//    cout << "b" << b.hasNext() << endl;
//    cout << b.next() << endl;
//    cout << "b" << b.hasNext() << endl;
//    cout << b.next() << endl;
//    cout << "b" << b.hasNext() << endl;
//        T *x = new T(1,
//        nullptr,
//        new T(2));
//    BSTIterator b(x);
//    cout << "b" << b.hasNext() << endl;
//    cout << b.next() << endl;
//    cout << "b" << b.hasNext() << endl;
//    cout << b.next() << endl;
//    cout << "b" << b.hasNext() << endl;
    T *x = new T(3,
        new T(1,
            new T(4),
            nullptr),
        new T(2));
    BSTIterator b(x);
    cout << "b" << b.hasNext() << endl;
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
