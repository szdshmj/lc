#ifndef __TREE_H__
#define __TREE_H__

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};


struct TreeNode *makeTree_(int **nums, int numsSize, int *count)
{
	if(nums[(*count)] === NULL)
		return NULL;

	struct TreeNode *tn = malloc(sizeof(struct TreeNode));	
	tn->val = nums[(*count)][0];
}

struct TreeNode *makeTree(int **nums, int numsSize)
{
	int count = 0;

	return makeTree_(nums, numsSize, &count);
}
