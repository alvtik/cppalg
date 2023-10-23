// Determine if binary tree is height-balanced

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
#include <algorithm>
#include <functional>

bool isBalanced(TreeNode* root) {
	std::function<int(TreeNode*)> height = [&](TreeNode* root) {
		if (!root) {
			return 0;
		}
		int l = height(root->left);
		int r = height(root->right);
		if (l == -1 || r == -1 || abs(l - r) > 1) {
			return -1;
		}
		return 1 + std::max(l, r);
	};
	return height(root) >= 0;
}
