#include "../inc.h"

bool dfs(struct TreeNode *root, int min, int max)
{
	if(root == NULL) return true;
	if(min > max) return false;
	if(root->val < min || root->val > max) return false;
	if(root->left == NULL && root->right == NULL) return true;
	if((root->left) && (root->left->val >= root->val)) return false;
	if((root->right) && (root->right->val <= root->val)) return false;
	if((root->left) && (root->right) && root->left->val >= root->right->val) return false;
	if(dfs(root->left,min, (max == INT_MAX ? root->val -1: max)) == false) return false;
	return dfs(root->right, (min == INT_MIN ? root->val +1 : min), max);
}

bool isValidBST(struct TreeNode* root) {

	return dfs(root, INT_MIN, INT_MAX);
}
