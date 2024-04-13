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
		if (node == nullptr) return;
		if (cntLvl > lSum.size()) lSum.push_back(0);
		lSum[cntLvl - 1] += node->val;
		dfs(node->left, lSum, cntLvl + 1);
		dfs(node->right, lSum, cntLvl + 1);
	}
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> lSum;
        dfs(root, lSum, 1);
        long long *lSumArr = new long long[lSum.size()];
        int *r = new int[lSum.size()];
        if (k > lSum.size()) return -1;
        for (int i = 0; i < lSum.size(); i++) {
        	lSumArr[i] = lSum[i];
        	r[i] = i;
        }
        sort(r, r + lSum.size(), [lSumArr](const int &a, const int &b)->bool{
        	return lSumArr[a] > lSumArr[b];
		});
        return lSumArr[r[k - 1]];
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
