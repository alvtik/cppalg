// Find target sum path

/*

Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the
sum of the node values in the path equals targetSum. Each path should be returned as a list of the
node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node
with no children.

*/

#include <vector>
#include <functional>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
std::vector<std::vector<int>> findTargetSumPath(TreeNode* root, int targetSum) {
	
	std::vector<std::vector<int>> result;
	std::vector<int> sumPath;
	
	std::function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int s) {
		
		if(root == nullptr)
			return;
		
		s -= root->val;
		sumPath.emplace_back(root->val);
		
		if(root->left == nullptr && root->right == nullptr && s == 0)
			result.emplace_back(sumPath);
		
		dfs(root->left, s);
		dfs(root->right, s);
		
		sumPath.pop_back();
	};
	
	dfs(root, targetSum);
	return result;
}
