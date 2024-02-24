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
	void dfs(TreeNode *node, vector<long long> &lSum, int cntLvl) {
		if (cntLvl > lSum.size()) lSum.push_back(0);
		lSum[cntLvl - 1] += node->val;
		if (node->left != nullptr) dfs(node->left, lSum, cntLvl + 1);
		if (node->right != nullptr) dfs(node->right, lSum, cntLvl + 1);
	}
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> lSum;
        dfs(root, lSum, 1);
        if (k > lSum.size()) return -1;
        sort(lSum.begin(), lSum.end(), greater<long long>());
        return lSum[k - 1];
    }
};

int main() {
	Solution s;
	TreeNode *root = new TreeNode(
		5,
		new TreeNode(
			8,
			new TreeNode(
				2,
				new TreeNode(4),
				new TreeNode(6)
			),
			new TreeNode(1)
		),
		new TreeNode(
			9,
			new TreeNode(3),
			new TreeNode(7)
		)
	);
	long long r = s.kthLargestLevelSum(root, 2);
	cout << r << endl;
	return 0;
}
