void dfs(struct TreeNode *root, int *nums, int *returnSize) {

	if(root->left) 
		dfs(root->left, nums, returnSize);

	nums[(*returnSize)++] = root->val;

	if(root->right) 
		dfs(root->right, nums, returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {

	int *nums = NULL;

	*returnSize = 0;
	if(root) {

		nums = malloc(sizeof(int) * 1000);
		dfs(root, nums, returnSize);
	}

	return nums;
}
