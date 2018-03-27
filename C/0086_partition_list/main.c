#include "../inc.h"
#include "../node.h"

struct ListNode* partition(struct ListNode* head, int x) {
	
	struct ListNode *l1 = NULL, *e1 = NULL, *l2 = NULL, *e2 = NULL;

	while(head) {

		if(head->val < x) {
			if(e1 == NULL) {
				l1 = head;
				e1 = head;
			}
			else {
				e1->next = head;
				e1 = head;
			}
		}
		else {
			if(e2 == NULL) {
				l2 = head;
				e2 = head;
			}
			else {
				e2->next = head;
				e2 = head;
			}
		}

		head = head->next;
	}

	if(e1 && e1->next != NULL) e1->next = NULL;
	if(e2 && e2->next != NULL) e2->next = NULL;
	if(!l1) return l2;
	if(!l2) return l1;
	
	e1->next = l2;
	return l1;
}

int main()
{
	int a[] = {1, 4, 3, 2, 5, 2};
	struct ListNode *head = makeList(a, sizeof(a) / sizeof(a[0]));

	head = partition(head, 3);
	dump_list_node(head);

	return 0;
}
