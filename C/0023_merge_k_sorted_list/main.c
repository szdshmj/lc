#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../node.h"
struct ListNode* merge2List(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode *t = NULL, *tmp, *curr = NULL;

	while(l1 && l2) {

		if(l1->val < l2->val) {
			tmp = l1;
			l1 = l1->next;
		}
		else {
			tmp = l2;
			l2 = l2->next;
		}

		if(t == NULL)
			t = tmp;
		else
			curr->next = tmp;

		curr = tmp;
		curr->next = NULL;
	}

	if(curr)
		curr->next = (l1 == NULL) ? l2 : l1;
	else
		t = (l1 == NULL) ? l2 : l1;

	return t;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {

	if(!lists)
		return NULL;

	while(listsSize > 1) {

		if(listsSize % 2 == 1)
			lists[0] = merge2List(lists[0], lists[listsSize-- - 1]);

		for(int i = 0; i < listsSize; i += 2)
			lists[i / 2] = merge2List(lists[i], lists[i + 1]);

		listsSize /= 2;
	}

	return lists[0];
}
