#include "include_all.h"

int findLucky(int a[], int length) {
	int times_a[length];
	memset(times_a, 0, sizeof(times_a));
	for (int i = 0; i != length; i++) {
		int ai = a[i];
		if (ai <= length) {
			times_a[ai - 1]++;
		}
	}
	for (int i = length; i != 0; i--) {
		int times = times_a[i - 1];
		if (times == i) {
			return times;
		}
	}
	return -1;
}