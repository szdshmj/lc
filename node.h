#ifndef __NODE_H__
#define __NODE_H__

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* makeList(int *a, int n) {

	struct ListNode *tmp, *head = NULL, *cur;

	if(a == NULL || n == 0)
		return NULL;
	
	for(int i = 0; i < n; i++) {
		tmp = (struct ListNode *)calloc(1, sizeof(struct ListNode));
		tmp->val = a[i];
		if(i == 0)
			head = tmp;
		else
			cur->next = tmp;
		cur = tmp;
	}

	return head;
}

void dump(struct ListNode *l) {

	if(!l)
		return;

	while(l) {

		printf("%d ", l->val);
		l = l->next;
	}
	printf("\n");
}
#endif
