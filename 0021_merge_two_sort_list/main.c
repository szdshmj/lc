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

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {

	struct ListNode *l3 = NULL, *l, *t[2] = {NULL, NULL};

	if(l1 == NULL)
		return l2;
	else if(l2 == NULL)
		return l1;

	while(l1 != NULL && l2 != NULL) {
		if(l1->val == l2->val) {
			t[0] = l1;
			l1 = l1->next;
			t[1] = l2;
			l2 = l2->next;
		}
		else {

			if(l1->val < l2->val) {
				t[0] = l1;
				l1 = l1->next;
			}
			else {
				t[0] = l2;
				l2 = l2->next;
			}
		}
		if(l3 == NULL) {
			l3 = t[0];
			l = l3;
		}
		else {
			l->next = t[0];
			l = l->next;
		}
		if(t[1]) {
			l->next = t[1];
			l = l->next;
			t[1] = NULL;
		}
	}

	if(l1 != NULL)
		l->next = l1;
	else if(l2 != NULL)
		l->next = l2;

	return l3;
}

int main()// 1->2->4, 1->3->4
{
	int a[] = {1, 2, 4}, b[] = {1, 3, 4};	
	struct ListNode *l1, *l2, *l3;
	
	l1 = makeList(a, sizeof(a) / sizeof(a[0]));
	dump(l1);
	l2 = makeList(b, sizeof(b) / sizeof(b[0]));
	dump(l2);
	l3 = mergeTwoLists(l1, l2);
	dump(l3);

	return 0;
}
