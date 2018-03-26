#include "../inc.h"
#include "../node.h"

struct ListNode* deleteDuplicates(struct ListNode* head) {

	struct ListNode *base, *p, *q;

	if(head == NULL || head->next == NULL) return head;

	while(head) {

		p = head->next;
		if(p == NULL) return head;
		while(p && head->val == p->val)
			p = p->next;

		if(p == NULL) return NULL;
		if(p == head->next) break;

		head = p;
	}

	p = head->next;
	q = head;

	while(p) {
		base = p;
		while(p->next && p->next->val == base->val) 
			p = p->next;

		if(p == base) {//don't move
			q = p;
			p = p->next;
		}
		else {
			p = p->next;
			q->next = p;
		}
	}

	return head;
}

int main()
{
	int a[] = {1, 1, 2};
	struct ListNode *head = makeList(a, sizeof(a) / sizeof(a[0]));

	head = deleteDuplicates(head);
	dump_list_node(head);

	return 0;
}
