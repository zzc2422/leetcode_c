#include "include_all.h"

int maxSubArray(const int a[], int length) {
	const int* end_np = a + length;
	int sum = a[0], max_sum = sum;
	while (1) {
		a++;
		if (a == end_np) {
			return max_sum;
		}
		if (sum < 0) {
			sum = 0;
		}
		sum += *a;
		if (sum > max_sum) {
			max_sum = sum;
		}
	}
}