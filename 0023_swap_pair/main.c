#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../node.h"

struct ListNode* swapPairs(struct ListNode* head) {
 
	struct ListNode *grab, *t = NULL, *pos;

	if(head == NULL || head->next == NULL)
		return head;

	while(head) {
		
		grab = head;
		if(head->next)
			head = head->next;

		head = head->next;
		
		if(grab->next) {

			struct ListNode *tmp = grab->next;
			tmp->next = grab;
			grab->next = NULL;
			grab = tmp;
		}
			
		if(t == NULL)
			t = grab;
		else 
			pos->next = grab;
			
		if(grab->next)
			pos = grab->next;
		else
			pos = grab;
	}
	return t;
}

int main()
{
	int a[]	= {0, 1, 2, 3, 4, 5, 6};
	struct ListNode * head = makeList(a, sizeof(a) / sizeof(a[0]));

	dump(head);
	head = swapPairs(head);

	dump(head);
}
