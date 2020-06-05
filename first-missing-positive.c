#include "include_all.h"

int firstMissingPositive(int a[], int length) {
	for (int* p = a; p != a + length; p++) {
		if (*p < 0) {
			*p = 0;
		}
	}
	for (int* p = a; p != a + length; p++) {
		int value = *p;
		if (value < 0) {
			value &= INT_MAX;
		}
		if (value > 0 && value <= length) {
			a[value - 1] |= INT_MIN;
		}
	}
	for (int* p = a; p != a + length; p++) {
		if (*p >= 0) {
			return p - a + 1;
		}
	}
	return length + 1;
}