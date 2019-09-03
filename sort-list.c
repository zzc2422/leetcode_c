#include "include_all.h"

#define POWER 32

// 注意：链表两部分长度都至少为1
static struct ListNode* _merge_sort(struct ListNode* start1_p,
				    struct ListNode* start2_p,
				    const struct ListNode* end_np) {
	const struct ListNode* end1_np = start2_p;
	struct ListNode head_prev, *p = &head_prev;
	while (1) {
		int value1 = start1_p->val, value2 = start2_p->val;
		if (value1 < value2) {
			p->next = start1_p;
			p = start1_p;
			start1_p = start1_p->next;
			if (start1_p == end1_np) {
				p->next = start2_p;
				return head_prev.next;
			}
		} else {
			p->next = start2_p;
			p = start2_p;
			start2_p = start2_p->next;
			if (start2_p == end_np) {
				p->next = start1_p;
				return head_prev.next;
			}
		}
	}
}

// 假定链表长度不超过2^POWER
struct ListNode* sortList(struct ListNode* head_p) {
	int index = 2;
	struct ListNode* node_p = head_p;
	struct ListNode *stack_pa[POWER], **spp = stack_pa + 1;
	stack_pa[0] = head_p;
	while (node_p != NULL) {
		struct ListNode* next_p = node_p->next;
		*spp = next_p;
		spp++;
		for (int tmp_index = index; (tmp_index & 1) == 0;
		     tmp_index >>= 1) {
			spp--;
			struct ListNode* start_node_p = *(spp - 1);
			node_p = _merge_sort(start_node_p, node_p, next_p);
			*(spp - 1) = node_p;
		}
		node_p = next_p;
	}
	head_p = stack_pa[0];
	if (spp != stack_pa + 1) {
		head_p = _merge_sort(head_p, stack_pa[1], NULL);
	}
	return head_p;
}