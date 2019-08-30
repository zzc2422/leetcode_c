#include "include_all.h"

static struct ListNode* _insert_point(struct ListNode* head_pre_p, int number) {
	struct ListNode* p = head_pre_p;
	while (1) {
		struct ListNode* next_p = p->next;
		int next_number = next_p->val;
		if (next_number >= number) {
			return p;
		}
		p = next_p;
	}
}

// 注意：new_pre_p不能比old_pre_p靠后
static void _move(struct ListNode* new_pre_p, struct ListNode* old_pre_p) {
	struct ListNode *to_move_p = old_pre_p->next,
			*old_next_p = to_move_p->next;
	old_pre_p->next = old_next_p;
	struct ListNode* new_next_p = new_pre_p->next;
	new_pre_p->next = to_move_p;
	to_move_p->next = new_next_p;
}

struct ListNode* insertionSortList(struct ListNode* head_p) {
	if (head_p == NULL) {
		return head_p;
	}
	struct ListNode *p = head_p, *next_p = p->next;
	struct ListNode head_pre;
	head_pre.next = head_p;
	while (next_p != NULL) {
		int number = next_p->val;
		struct ListNode* insert_p = _insert_point(&head_pre, number);
		struct ListNode* next_next_p = next_p->next;
		if (p == insert_p) {
			p = next_p;
		} else {
			_move(insert_p, p);
		}
		next_p = next_next_p;
	}
	return head_pre.next;
}