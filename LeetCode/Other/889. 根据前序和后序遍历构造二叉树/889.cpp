#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

	struct TreeNode {
	    int val;
	    TreeNode *left;
	    TreeNode *right;
	    TreeNode() : val(0), left(nullptr), right(nullptr) {}
	    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
	};

class Solution {
public:
	void build(TreeNode *cnt, int &prePos, vector<int>& preorder, vector<int>& postorder, unordered_map<int, int> &posMap) {
		int oPrePos = prePos;
		if (prePos < preorder.size() - 1 && posMap[preorder[prePos + 1]] < posMap[preorder[oPrePos]]) {
			TreeNode *lc = new TreeNode(preorder[++prePos]);
			cnt->left = lc;
			build(lc, prePos, preorder, postorder, posMap);
		}
		if (prePos < preorder.size() - 1 && posMap[preorder[prePos + 1]] < posMap[preorder[oPrePos]]) {
			TreeNode *rc = new TreeNode(preorder[++prePos]);
			cnt->right = rc;
			build(rc, prePos, preorder, postorder, posMap);
		}
	}
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
		unordered_map<int, int> posMap;
		for (int i = 0; i < postorder.size(); i++)
			posMap[postorder[i]] = i;
		int prePos = 0;
		TreeNode *root = new TreeNode(preorder[prePos]);
		build(root, prePos, preorder, postorder, posMap);
		return root;
    }
};

void printMid(TreeNode *x) {
	if (x->left != nullptr) printMid(x->left);
	printf("%d ", x->val);
	if (x->right != nullptr) printMid(x->right);
}

int main() {
	Solution s;
	vector<int> vpre = { 1, 2, 4, 5, 3, 6, 7 };
	vector<int> vpost = { 4, 5, 2, 6, 7, 3, 1 };
	TreeNode *t = s.constructFromPrePost(vpre, vpost);
	printMid(t);
	return 0;
}
