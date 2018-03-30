
void dfs(struct TreeNode **ret, int start, int end, int *returnSize)
{
	for(int i = start; i <= end; i++) {
	}
}

struct TreeNode** generateTrees(int n, int* returnSize) {
    
	*(returnSize) = 0;

	struct TreeNode **ret = malloc(sizeof(struct TreeNode *) * 1000);

	return dfs(ret, 1, n, returnSize);
}
