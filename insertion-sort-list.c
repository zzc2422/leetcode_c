#include "include_all.h"

static struct ListNode* _insert_point(struct ListNode* head_prev_p,
				      int number) {
	struct ListNode* p = head_prev_p;
	while (1) {
		struct ListNode* next_p = p->next;
		int next_number = next_p->val;
		if (next_number >= number) {
			return p;
		}
		p = next_p;
	}
}

struct ListNode* insertionSortList(struct ListNode* head_p) {
	if (head_p == NULL) {
		return head_p;
	}
	struct ListNode head_prev = {.next = head_p};
	struct ListNode *end_p = head_p, *p = head_p->next;
	while (p != NULL) {
		struct ListNode* next_p = p->next;
		struct ListNode* insert_p = _insert_point(&head_prev, p->val);
		if (insert_p == end_p) {
			end_p = p;
		} else {
			p->next = insert_p->next;
		}
		insert_p->next = p;
		end_p->next = next_p;
		p = next_p;
	}
	end_p->next = NULL;
	return head_prev.next;
}