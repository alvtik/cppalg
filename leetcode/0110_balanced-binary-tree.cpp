#include <algorithm>

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

class Solution
{
public:
	bool isBalanced(TreeNode* root)
	{
		return isBalancedPriv(root) >= 0;
	}
	
private:
	int isBalancedPriv(TreeNode* node)
	{
		if (!node)
			return 0;

		int nL = isBalancedPriv(node->left); 
		int nR = isBalancedPriv(node->right);

		if(nL == -1 || nR == -1 || std::abs(nR - nL) > 1) 
			return -1;

		return 1 + std::max(nL, nR);
	}
};