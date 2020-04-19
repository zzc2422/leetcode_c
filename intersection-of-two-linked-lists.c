#include "include_all.h"

static int _dis_1m2(struct ListNode* head1_p, struct ListNode* head2_p) {
	unsigned step = 1, dis1 = 0, dis2 = 0;
	struct ListNode *p1 = head1_p, *p2 = head2_p;
	while (1) {
		for (unsigned i = 1;; i++) {
			if (p1 == p2) {
				return (int)(dis1 - dis2);
			} else if (p1 == NULL) {
				break;
			}
			p1 = p1->next;
			dis1++;
			if (i == step) {
				break;
			}
		}
		step <<= 1;
		for (unsigned i = 1;; i++) {
			if (p1 == p2) {
				return (int)(dis1 - dis2);
			} else if (p2 == NULL) {
				break;
			}
			p2 = p2->next;
			dis2++;
			if (i == step) {
				break;
			}
		}
		step <<= 1;
	}
}

struct ListNode* getIntersectionNode(struct ListNode* head1_p,
				     struct ListNode* head2_p) {
	struct ListNode *p1 = head1_p, *p2 = head2_p;
	int dis_1m2 = _dis_1m2(head1_p, head2_p);
	if (dis_1m2 >= 0) {
		for (int i = 0; i != dis_1m2; i++) {
			p1 = p1->next;
		}
	} else {
		for (int i = 0; i != dis_1m2; i--) {
			p2 = p2->next;
		}
	}
	while (p1 != p2) {
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}