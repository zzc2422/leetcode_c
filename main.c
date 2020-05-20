#include "include_all.h"

struct ListNode* reverseKGroup(struct ListNode* head_p, int k);

int main() {
	struct ListNode n2 = {.val = 2, .next = NULL},
			n1 = {.val = 1, .next = &n2};
	reverseKGroup(&n1, 2);
	return 0;
}
/*







































*/