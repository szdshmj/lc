#include "../inc.h"

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {

    if(p == NULL && q == NULL) return true;
    if(p == NULL && q != NULL) return false;
    if(p != NULL && q == NULL) return false;
    if(p->val != q->val) return false;

    if(isSameTree(p->left, q->left) == false)
        return false;
    return isSameTree(p->right, q->right);
}
