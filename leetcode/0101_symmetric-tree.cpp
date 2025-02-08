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
	bool isSymmetric (TreeNode* root)
	{
		return isSymmetric(root->left, root->right);
	}

	bool isSymmetric(TreeNode* l, TreeNode* r)
	{
		if(l && r && l->val == r->val)
			return isSymmetric(l->right, r->left) && isSymmetric(l->left, r->right);

		if(!l && !r)
			return true;

		return false;
	}
};