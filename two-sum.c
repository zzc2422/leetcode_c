#include "include_all.h"

static int _int_cmp_1gp(const void* p1, const void* p2) {
	int value1 = *(const int*)p1, value2 = *(const int*)p2;
	return value1 - value2;
}

const int* _bin_find(const int* start_p, const int* end_p, int target) {
	while (1) {
		size_t length_m1 = end_p - start_p;
		size_t half_length = length_m1 >> 1;
		const int* left_end_p = start_p + half_length;
		int middle = *left_end_p;
		if (start_p == end_p) {
			if (middle == target) {
				return left_end_p;
			} else {
				return NULL;
			}
		}
		if (target <= middle) {
			end_p = left_end_p;
		} else {
			start_p = left_end_p + 1;
		}
	}
}

int* twoSum(int a[], int length, int target, int* two_p) {
	int tmp_a[length];
	memcpy(tmp_a, a, sizeof(int[length]));
	qsort(tmp_a, length, sizeof(int), _int_cmp_1gp);
	const int *start_p = tmp_a, *end_p = tmp_a + length - 1;
	int target1, target2;
	while (1) {
		target1 = *start_p;
		target2 = target - target1;
		const int* p = _bin_find(start_p + 1, end_p, target2);
		if (p != NULL) {
			break;
		}
		start_p++;
	}
	int *result_a = malloc(sizeof(int[2]));
	for (const int* p = a; p != a + length; p++) {
		int value = *p;
		if (value == target1) {
			result_a[0] = p - a;
			target1 = INT_MIN;
		} else if (value == target2) {
			result_a[1] = p - a;
		}
	}
	*two_p = 2;
	return result_a;
}