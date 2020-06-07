#include "include_all.h"

static const int* _bin_search(const int* start_p, const int* end_p,
			      int target) {
	while (start_p != end_p) {
		size_t length_m1 = end_p - start_p;
		size_t half = length_m1 >> 1;
		const int* left_end_p = start_p + half;
		int left_end_value = *left_end_p;
		if (target > left_end_value) {
			start_p = left_end_p + 1;
		} else {
			end_p = left_end_p;
		}
	}
	return start_p;
}

int searchInsert(int a[], int length, int target) {
	if (length == 0) {
		return 0;
	}
	const int* end_p = a + length - 1;
	if (target > *end_p) {
		return length;
	}
	const int* insert_p = _bin_search(a, end_p, target);
	return insert_p - a;
}