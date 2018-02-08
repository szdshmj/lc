#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

	int i = 0;
	while(l) {

		printf("%d ", l->val);
		l = l->next;
		if(i == 0) i = 1;
	}
	if(i == 1) printf("\n");
}

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
