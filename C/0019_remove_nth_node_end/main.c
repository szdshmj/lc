#include "../inc.h"
#include "../node.h"

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {

	struct ListNode* first = head, *second = head;
	int i = 0;

	if(head == NULL || n < 0)
		return NULL;

	for(i = 0; i < n && first; i++)
		first = first->next;

	if (!first) {
		if(i == n)
			return head->next;
		else
			return NULL;
	}

//first point to n
	while(first->next) {
		first = first->next;
		second = second->next;
	}

	first = second->next;
	second->next = first->next;
	return head;
}

int main()
{
	//int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};	
	int a[] = {1, 2};	
	struct ListNode *ln, *re;
	
	ln = makeList(a, sizeof(a) / sizeof(a[0]));
	dump(ln);
	ln = removeNthFromEnd(ln, 2);
	dump(ln);

	return 0;
}
