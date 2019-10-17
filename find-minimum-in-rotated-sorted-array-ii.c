#include "include_all.h"

int findMin(const int a[], int length) {
	const int *left_p = a, *right_p = a + length - 1;
	int left_value = *left_p, right_value = *right_p;
	while (left_p != right_p) {
		if (left_value == right_value) {
			right_p--;
			right_value = *right_p;
			continue;
		} else if (left_value < right_value) {
			return left_value;
		}
		const int* middle_p = left_p + (((right_p - left_p)) >> 1);
		int middle_value = *middle_p;
		if (middle_value < left_value) {
			right_p = middle_p;
			right_value = middle_value;
		} else {
			left_p = middle_p + 1;
			left_value = *left_p;
		}
	}
	return left_value;
}