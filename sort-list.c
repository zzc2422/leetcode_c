#include "include_all.h"

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
	if (head_p == NULL) {
		return NULL;
	}
	int index = 2;
	struct ListNode* node_p = head_p->next;
	struct ListNode *stack_pa[32], **spp = stack_pa, *top_p = head_p;
	stack_pa[0] = top_p;
	while (node_p != NULL) {
		struct ListNode* next_p = node_p->next;
		spp++;
		*spp = node_p;
		for (int tmp_index = index; (tmp_index & 1) == 0;
		     tmp_index >>= 1) {
			spp--;
			struct ListNode* start_node_p = *spp;
			node_p = _merge_sort(start_node_p, node_p, next_p);
			*spp = node_p;
		}
		top_p = node_p;
		node_p = next_p;
		index++;
	}
	// 至此，top_p为栈顶的值
	while (spp != stack_pa) {
		spp--;
		struct ListNode* left_p = *spp;
		top_p = _merge_sort(left_p, top_p, NULL);
	}
	return top_p;
}

int main() {
	struct ListNode node1, node2, node3;
	node1.val = 1;
	node1.next = &node2;
	node2.val = 7;
	node2.next = &node3;
	node3.val = 2;
	node3.next = NULL;
	struct ListNode* list_p = sortList(&node1);
	printf("%d\n", list_p->val);
	return 0;
}