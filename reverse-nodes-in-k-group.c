#include "include_all.h"

struct ListNode* reverseKGroup(struct ListNode* head_p, int k) {
	struct ListNode *hp, **pre_pp = &hp;
	while (1) {
		struct ListNode* tail_p = head_p;
		int i = 1;
		while (1) {
			if (tail_p == NULL) {
				*pre_pp = head_p;
				return hp;
			} else if (i == k) {
				break;
			}
			tail_p = tail_p->next;
			i++;
		}
		*pre_pp = tail_p;
		pre_pp = &(head_p->next);
		struct ListNode *current_p = NULL, *next_p = head_p;
		struct ListNode* next_next_p;
		while (1) {
			next_next_p = next_p->next;
			next_p->next = current_p;
			if (next_p == tail_p) {
				break;
			}
			current_p = next_p;
			next_p = next_next_p;
		}
		head_p = next_next_p;
	}
}