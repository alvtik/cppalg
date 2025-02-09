#include <vector>

class Solution
{
public:
	std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum)
	{
		std::vector<std::vector<int>> vRes;
		std::vector<int> vPath;
		
		if(root)
			findPaths(root, targetSum, vRes, vPath);

		return vRes;
	}

private:
	void findPaths(TreeNode* node, int targetSum,
				std::vector<std::vector<int>>& vRes, std::vector<int>& vPath)
	{
		vPath.push_back(node->val);
		const int nNewTarget = targetSum - node->val;

		if(nNewTarget == 0 && !node->left && !node->right)
		{
			vRes.push_back(vPath);
		}
		else
		{
			if(node->left)
				findPaths(node->left, nNewTarget, vRes, vPath);

			if(node->right)
				findPaths(node->right, nNewTarget, vRes, vPath);
		}
		
		vPath.pop_back();
	}
};