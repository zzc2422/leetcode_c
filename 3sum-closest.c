#include "include_all.h"

typedef struct {
	unsigned min_diff;
	int closest;
} dc_t;

static int _int_cmp_1gp(const void* p1, const void* p2) {
	int value1 = *(const int*)p1, value2 = *(const int*)p2;
	return value1 - value2;
}

static dc_t _two_closest(const int* start_p, const int* end_p,
			 int local_target) {
	const int *left_p = start_p, *right_p = end_p;
	int left_value = *left_p, right_value = *right_p, closest;
	unsigned min_diff = (unsigned)-1;
	while (left_p != right_p) {
		int diff = left_value - right_value;
		if (diff == 0) {
			dc_t dc = {.min_diff = 0, .closest = local_target};
			return dc;
		} else if (diff < 0) {
			diff = -diff;
			left_p++;
			left_value = *left_p;
		} else {
			right_p--;
			right_value = *right_p;
		}
		unsigned udiff = diff;
		if (udiff < min_diff) {
			min_diff = udiff;
			closest = diff;
		}
	}
	dc_t dc = {.min_diff = min_diff, .closest = closest};
	return dc;
}

int threeSumClosest(int a[], int length, int target) {
	qsort(a, length, sizeof(int), _int_cmp_1gp);
	const int *first_p = a, *end_p = a + length - 1;
	unsigned min_diff = (unsigned)-1;
	int closest;
	do {
		int first_value = *first_p, local_target = target - first_value;

		const int *left_p = first_p + 1, *right_p = end_p;
		int left_value = *left_p, right_value = *right_p;
		while (left_p != right_p) {
			int sum = left_value + right_value;
			int diff = sum - local_target;
			if (diff == 0) {
				return target;
			} else if (diff < 0) {
				diff = -diff;
				left_p++;
				left_value = *left_p;
			} else {
				right_p--;
				right_value = *right_p;
			}
			unsigned udiff = diff;
			if (udiff < min_diff) {
				min_diff = udiff;
				closest = first_value + sum;
			}
		}

		first_p++;
	} while (first_p + 1 != end_p);
	return closest;
}