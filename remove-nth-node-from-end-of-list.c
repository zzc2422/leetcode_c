#include "include_all.h"

struct ListNode* removeNthFromEnd(struct ListNode* head_p, int n) {
	const struct ListNode* front_node_p = head_p;
	for (int i = 0; i != n; i++) {
		front_node_p = front_node_p->next;
	}
	struct ListNode** pre_rem_pp = &head_p;
	struct ListNode* rem_p = head_p;
	while (front_node_p != NULL) {
		front_node_p = front_node_p->next;
		pre_rem_pp = &(rem_p->next);
		rem_p = *pre_rem_pp;
	}
	*pre_rem_pp = rem_p->next;
	return head_p;
}