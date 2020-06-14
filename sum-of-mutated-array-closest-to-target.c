#include "include_all.h"

static int _int_cmp_1gp(const void* p1, const void* p2) {
	int i1 = *(const int*)p1, i2 = *(const int*)p2;
	return i1 - i2;
}

int findBestValue(int a[], int length, int target) {
	qsort(a, length, sizeof(int), _int_cmp_1gp);
	const int *p = a, *endn_p = a + length;
	int prev_sum = 0;
	while (1) {
		int rest_amount = endn_p - p, value = *p;
		int sum = prev_sum + rest_amount * value;
		int addi_sum = sum - target;
		if (addi_sum > 0) {
			int sub = addi_sum / rest_amount;
			int mod = addi_sum % rest_amount;
			value -= sub;
			if ((mod << 1) >= rest_amount) {
				return value - 1;
			} else {
				return value;
			}
		}
		prev_sum += value;
		p++;
		if (p == endn_p) {
			return value;
		}
	}
}