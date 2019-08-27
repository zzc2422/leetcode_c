#include "include_all.h"

int candy(const int rate_a[], int stu_amount) {
	if (stu_amount == 0) {
		return 0;
	}
	const int *rate_end_np = rate_a + stu_amount, *p = rate_a + 1;
	int rate = rate_a[0], dec_length = 1, candy = 1, sum = 1;
	while (1) {
		int new_rate = *p;
		if (new_rate >= rate) {
			dec_length = 1;
			if (new_rate == rate) {
				candy = 1;
			} else {
				candy++;
			}
		} else {
			if (candy == 1) {
				sum += dec_length;
			} else {
				candy--;
			}
			dec_length++;
		}
		sum += candy;
	}
	return sum;
}