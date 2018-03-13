#include "../inc.h"
#include "../node.h"

struct ListNode* rotateRight(struct ListNode* head, int k) {

	struct ListNode *i = head, *j = head, *h = head;
	int m;

	if(head == NULL || k < 1)
		goto out;
	
	for(m = 0; m <= k && i; m++)
		i = i->next;

	if((i == NULL) && (m <= k)) {
		printf("m %d, k %d\n", m, k);
		goto out;
	}

	while(i != NULL) {
		i = i->next;
		j = j->next;
	}

	i = j->next;
	j->next = NULL;
	
	head = i;
	while(i->next) i = i->next;
	i->next = h;
out:
	return head;
}

int main()
{
	//int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};	
	int a[] = {1, 2};
	//int a[] = {1};
	struct ListNode* list = makeList(a, sizeof(a) / sizeof(a[0]));

	dump(list);
	list = rotateRight(list, 3);
	dump(list);

	return 0;
}
