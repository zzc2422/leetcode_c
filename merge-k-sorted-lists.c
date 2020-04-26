#include "include_all.h"

typedef struct {
	int value, index;
} ii_t;

static void _down(ii_t ii_a[], int length, int index_p1, ii_t value) {
	while (1) {
		int left_index_p1 = index_p1 << 1;
		if (left_index_p1 > length) {
			break;
		}
		int min_child_index_p1;
		ii_t left_value = ii_a[left_index_p1 - 1], min_child_value;
		if (left_index_p1 == length) {
			min_child_index_p1 = left_index_p1;
			min_child_value = left_value;
		} else {
			int right_index_p1 = left_index_p1 + 1;
			ii_t right_value = ii_a[right_index_p1 - 1];
			if (right_value.value < left_value.value) {
				min_child_index_p1 = right_index_p1;
				min_child_value = right_value;
			} else {
				min_child_index_p1 = left_index_p1;
				min_child_value = left_value;
			}
		}
		if (min_child_value.value >= value.value) {
			break;
		}
		ii_a[index_p1 - 1] = min_child_value;
		index_p1 = min_child_index_p1;
	}
	ii_a[index_p1 - 1] = value;
}

static void _make_min_heap(ii_t ii_a[], int length) {
	for (int index_p1 = length >> 1; index_p1 != 0; index_p1--) {
		_down(ii_a, length, index_p1, ii_a[index_p1 - 1]);
	}
}

struct ListNode* mergeKLists(struct ListNode* list_pa[], int list_amount) {
	ii_t ii_a[list_amount + 1], *ii_p = ii_a;
	struct ListNode** list_pp = list_pa;
	while (list_pp != list_pa + list_amount) {
		struct ListNode* list_p = *list_pp;
		if (list_p != NULL) {
			ii_p->value = list_p->val;
			ii_p->index = list_pp - list_pa;
			ii_p++;
		}
		list_pp++;
	}
	list_amount = ii_p - ii_a;
	if (list_amount == 0) {
		return NULL;
	}
	_make_min_heap(ii_a, list_amount);
	struct ListNode* list_start_p;
	struct ListNode** node_pp = &list_start_p;
	while (1) {
		ii_t ii = *ii_a;
		int index = ii.index;
		struct ListNode** list_pp = list_pa + index;
		struct ListNode* list_p = *list_pp;
		*node_pp = list_p;
		node_pp = &(list_p->next);
		list_p = *node_pp;
		if (list_p == NULL) {
			list_amount--;
			if (list_amount == 0) {
				break;
			}
			ii = ii_a[list_amount];
		} else {
			*list_pp = list_p;
			ii.value = list_p->val;
		}
		_down(ii_a, list_amount, 1, ii);
	}
	return list_start_p;
}
/*



































*/