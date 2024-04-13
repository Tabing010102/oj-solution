#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
	int pVal, qVal;
	bool pFlag = false, qFlag = false;
	TreeNode *ans = nullptr;
	void pdfs(TreeNode *cntNode) {
		if (ans != nullptr) return;
		int cCount = 0;
		bool opFlag = pFlag, oqFlag = qFlag;
		if (cntNode->left != nullptr) pdfs(cntNode->left);
		if (cntNode->right != nullptr) pdfs(cntNode->right);
		if (!opFlag && pFlag) cCount++;
		if (!oqFlag && qFlag) cCount++;
		int tCount = 0;
		if (cntNode->val == pVal) { pFlag = true; tCount++; }
		if (cntNode->val == qVal) { qFlag = true; tCount++; }
		if (ans == nullptr && pFlag && qFlag &&
			(cCount == 2 || (cCount == 1 && tCount == 1)) ) {
			ans = cntNode;
			return;
		}
	}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	pVal = p->val; qVal = q->val;
        pdfs(root);
        return ans;
    }
};

int main() {
	Solution s;
	TreeNode *root = new TreeNode(
		6,
		new TreeNode(
			2,
			new TreeNode(0),
			new TreeNode(
				4,
				new TreeNode(3),
				new TreeNode(5)
			)
		),
		new TreeNode(
			8,
			new TreeNode(7),
			new TreeNode(9)
		)
	);
//	auto ans = s.lowestCommonAncestor(root, new TreeNode(2), new TreeNode(8));
	auto ans = s.lowestCommonAncestor(root, new TreeNode(2), new TreeNode(4));
	cout << ans->val << endl;
	return 0;
}
