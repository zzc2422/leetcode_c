#include "include_all.h"

int candy(const int rate_a[], int stu_amount) {
	if (stu_amount == 0) {
		return 0;
	}
	const int *rate_end_np = rate_a + stu_amount;
	int rate = rate_a[0], dec_length = 1, candy = 1, sum = 1;
	for (const int *p = rate_a + 1; p != rate_end_np; p++) {
		int new_rate = *p;
		if (new_rate >= rate) {
			dec_length = 0;
			if (new_rate == rate) {
				candy = 1;
			} else {
				candy++;
			}
		} else {
			if (candy == 1) {
				sum += dec_length;
			} else {
				candy = 1;
			}
			dec_length++;
		}
		sum += candy;
		rate = new_rate;
	}
	return sum;
}

int main() {
	int rate_a[] = {1, 3, 4, 5, 2}, length = sizeof(rate_a) / sizeof(int);
	printf("%d\n", candy(rate_a, length));
}