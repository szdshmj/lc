#include "../inc.h"
#include "../node.h"

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {

	struct ListNode dummy = {0, head}, *pm, *pn, *tail, *s, *e;
	int i;

	if(head == NULL || head->next == NULL) return head;
	
	pm = &dummy;

	for(i = 0; i < m - 1; i++) pm = pm->next;
	pn = pm;
	for(; i < n; i++) pn = pn->next;
	tail = pn->next;

	s = pm->next;
	e = pn->next;

	while(s != e) {
		struct ListNode *p = s;
		s = s->next;
		p->next = tail;
		tail = p;
	}
	pm->next = tail;

	return dummy.next;
}


int main(int argc, char **argv)
{
	int a[argc -1];
	
	for(int i = 0; i < argc - 1; i++)
		a[i] = atoi(argv[i + 1]);

	struct ListNode *list = makeList(a, argc - 1);

	list = reverseBetween(list, 1 , 4);
	dump_list_node(list);
}
