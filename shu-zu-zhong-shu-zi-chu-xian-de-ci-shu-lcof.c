#include "include_all.h"

int* singleNumbers(int a[], int length, int* two_p) {
	const int* endn_p = a + length;
	unsigned xor_all = 0;
	for (const int* p = a; p != endn_p; p++) {
		xor_all ^= *p;
	}
	int right_bit = 16, right_bit_sum = 0;
	do {
		unsigned new_xor_all = xor_all >> right_bit;
		if (new_xor_all != 0) {
			right_bit_sum += right_bit;
			xor_all = new_xor_all;
		}
		right_bit >>= 1;
	} while (right_bit != 0);
	xor_all = 1 << right_bit_sum;
	int xor0 = 0, xor1 = 0;
	for (const int* p = a; p != endn_p; p++) {
		int value = *p;
		if (value & xor_all) {
			xor1 ^= value;
		} else {
			xor0 ^= value;
		}
	}
	int* result_a = malloc(sizeof(int[2]));
	result_a[0] = xor0;
	result_a[1] = xor1;
	*two_p = 2;
	return result_a;
}