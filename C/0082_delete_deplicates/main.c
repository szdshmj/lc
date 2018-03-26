#include "../inc.h"
#include "../node.h"

struct ListNode* deleteDuplicatesWithDummy(struct ListNode* head) {

	struct ListNode dummy = {0, head};
	struct ListNode *p = head, *next = head, *prev = &dummy;

	while (p != NULL) {

		while (next != NULL && next->val == p->val)
			next = next->next;

		if (p->next == next)
			prev = p;
		else
			prev->next = next;

		p = next;
	}
	return dummy.next;
}

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
	int a[] = {1, 1, 1, 2, 3, 3, 3, 3, 4};
	struct ListNode *head = makeList(a, sizeof(a) / sizeof(a[0]));

	head = deleteDuplicatesWithDummy(head);
	dump_list_node(head);

	return 0;
}
