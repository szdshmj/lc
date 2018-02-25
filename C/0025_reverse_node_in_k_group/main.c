#include "../inc.h"
#include "../node.h"

struct ListNode* fetch_k_nodes(struct ListNode** left, int k) {

	int count = 0;
	struct ListNode *tmp = *left, *r = NULL;

	tmp = *left;

	while(*left && count < k) {count++; (*left) = (*left)->next;}

	if(count < k || tmp == NULL)
		return tmp;

	for(int i = 0; i < k; i++) {
		
		struct ListNode *h = tmp;

		tmp = tmp->next;

		if(r == NULL) {
			r = h;
			r->next = NULL;
		}
		else {
			h->next = r;
			r = h;
		}
	}

	return r;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {

	struct ListNode *left = head, *pos = NULL, *fin = NULL, *k_nodes = NULL;

	if(head == NULL || head->next == NULL || k < 2)
		return head;
	
	while(left) {

		if((k_nodes = fetch_k_nodes(&left, k)) == NULL)
			break;

		if(pos)
			pos->next = k_nodes;
		else {
			pos = k_nodes;
			fin = pos;
		}
		while(pos->next) pos = pos->next;
	}
	return fin;
}

int main(int argc, char *argv[])
{
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	struct ListNode *list = makeList(a, sizeof(a) / sizeof(a[0]));
	
	dump(list);
	list = reverseKGroup(list, atoi(argv[1]));
	dump(list);

	return 0;
}
