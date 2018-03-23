#include "../inc.h"

struct ListNode* deleteDuplicates(struct ListNode* head) {

	struct ListNode *p = head, *q = head;

	if(!head) return head;

	while(q != NULL) {
		q = p->next;
		while(q && q->val == p->val)
			q = q->next;

		p->next = q;
		if(q == NULL) break;

		p = q;
	}
	return head;
}
