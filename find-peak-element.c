#include <stdlib.h>

int findPeakElement(const int a[], int length) {
	size_t length_n = length - 1;
	const int *left_p = a, *right_p = a + length_n;
	while (length_n != 0) {
		size_t left_length_n = length_n >> 1;
		const int* middle_p = left_p + left_length_n;
		int middle_value = middle_p[0];
		int middle_right_value = middle_p[1];
		if (middle_value < middle_right_value) {
			left_p = middle_p + 1;
		} else {
			right_p = middle_p;
		}
		length_n = right_p - left_p;
	}
	return left_p - a;
}