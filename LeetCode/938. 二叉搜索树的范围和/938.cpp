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
	int L, R;
	int ans = 0;
	void mDfs(TreeNode *cntNode) {
		if (cntNode->left && cntNode->val > L) mDfs(cntNode->left);
		if (cntNode->val >= L && cntNode->val <= R) ans += cntNode->val;
		if (cntNode->right && cntNode->val < R) mDfs(cntNode->right);
	}
    int rangeSumBST(TreeNode* root, int low, int high) {
    	L = low; R = high;
		mDfs(root);
		return ans;
    }
};

int main() {
	Solution s;
	TreeNode *root = new TreeNode(
		10,
		new TreeNode(
			5,
			new TreeNode(
				3,
				new TreeNode(1),
				nullptr
			),
			new TreeNode(
				7,
				new TreeNode(6),
				nullptr
			)
		),
		new TreeNode(
			15,
			new TreeNode(13),
			new TreeNode(18)
		)
	);
	auto ans = s.rangeSumBST(root, 6, 10);
	cout << ans << endl;
	return 0;
}
