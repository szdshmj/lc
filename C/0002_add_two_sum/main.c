#include "../inc.h"

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
	struct ListNode *head = NULL, *tmp, *p, *left = NULL, *ll2 = l2;

	int step = 0;

	while(l1 && l2) {

		l1->val = l1->val + l2->val + step;
		if(l1->val >= 10) {
			l1->val -= 10;
			step = 1;
		}
		else
			step = 0;

		if(head == NULL)
			head = l1;
		else
			p->next = l1;

		p = l1;
		l1=l1->next; 
		l2=l2->next; 
	} 

	if(l1) 
		left = l1;
	else if(l2)
		left = l2;

	if(!left && step == 0)
		return head;

	p->next = left;

	while(left && step == 1) {

		if(left->next == NULL)
			p = left;

		left->val += step;
		if(left->val >= 10) {
			step = 1;
			left->val -= 10;
		}
		else
			step = 0;
		left = left->next;
	}

	if(step == 1) {
		ll2->val = 1;
		ll2->next = NULL;
		p->next = ll2;
	}
	return head;
}
