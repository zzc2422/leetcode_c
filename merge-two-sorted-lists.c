#include "include_all.h"

struct ListNode* mergeTwoLists(struct ListNode* l1_p, struct ListNode* l2_p) {
	struct ListNode* head_p;
	struct ListNode** node_pp = &head_p;
	while (1) {
		if (l1_p == NULL) {
			*node_pp = l2_p;
			return head_p;
		} else if (l2_p == NULL) {
			*node_pp = l1_p;
			return head_p;
		}
		int value1 = l1_p->val, value2 = l2_p->val;
		struct ListNode* next_node_p;
		if (value1 <= value2) {
			next_node_p = l1_p;
			l1_p = l1_p->next;
		} else {
			next_node_p = l2_p;
			l2_p = l2_p->next;
		}
		*node_pp = next_node_p;
		node_pp = &(next_node_p->next);
	}
}