#include "include/list.h"
#include "include_all.h"

struct ListNode* swapPairs(struct ListNode* head_p) {
	struct ListNode *node_p = head_p, **node_pp = &head_p;
	while (node_p != NULL) {
		struct ListNode* next_node_p = node_p->next;
		if (next_node_p == NULL) {
			break;
		}
		struct ListNode* next_next_node_p = next_node_p->next;
		*node_pp = next_node_p;
		next_node_p->next = node_p;
		node_pp = &(node_p->next);
		node_p = next_next_node_p;
	}
	*node_pp = node_p;
	return head_p;
}