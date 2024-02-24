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
	void dfs(TreeNode *node, vector<int> &vals) {
		vals.push_back(node->val);
		if (node->left != nullptr) dfs(node->left, vals);
		if (node->right != nullptr) dfs(node->right, vals);
	}
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> vals;
        dfs(root, vals);
        sort(vals.begin(), vals.end());
        vector<vector<int>> ans;
        for (auto it = queries.begin(); it != queries.end(); it++) {
        	int x = *it;
        	auto mi = lower_bound(vals.rbegin(), vals.rend(), x, greater<int>());
        	auto ma = lower_bound(vals.begin(), vals.end(), x);
        	vector<int> t;
        	t.push_back(mi == vals.rend() ? -1 : *mi);
        	t.push_back(ma == vals.end() ? -1 : *ma);
        	ans.push_back(t);
        }
        return ans;
    }
};

int main() {
	Solution s;
	TreeNode *root = new TreeNode(
		6,
		new TreeNode(
			2,
			new TreeNode(1),
			new TreeNode(4)
		),
		new TreeNode(
			13,
			new TreeNode(9),
			new TreeNode(
				15,
				new TreeNode(14),
				nullptr
			)
		)
	);
	vector<int> x = {2, 5, 16};
	auto ans = s.closestNodes(root, x);
	for (auto it = ans.begin(); it != ans.end(); it++) {
		cout << (*it)[0] << " " << (*it)[1] << endl;
	}
	return 0;
}
