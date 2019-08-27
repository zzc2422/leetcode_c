// 未完成

#include "include_all.h"
#include <stdio.h>

static const char *_get_end_np(const char str_a[]) {
	const char *p;
	for (p = str_a; *p != '\0'; p++)
		;
	return p;
}

// cut_times_a[i]表示从str_start_p[i + 1]开始之后的串分割次数
static int _seg_amount(const char *str_start_p, const char *str_end_np,
		       const int *pl_start_p, const int *pl_end_np,
		       const int seg_amount_a[]) {
	int length = str_end_np - str_start_p, seg_amount = length;
	const int *p = pl_start_p;
	do {
		int palin_len = *p, after_len = length - palin_len;
		if (after_len <= 1) {
			return after_len + 1;
		}
		int sai = seg_amount_a[palin_len - 1] + 1;
		if (sai < seg_amount) {
			seg_amount = sai;
		}
		p++;
	} while (p != pl_end_np);
	return seg_amount;
}

int minCut(const char str_a[]) {
	const char *end_np = _get_end_np(str_a);
	if (end_np <= str_a + 1) {
		return 1;
	}
	int length = end_np - str_a;
	int palin_len_a[length];
	// cut_times_a[i]表示从str_a[i + 1]开始之后的串分割次数
	int seg_amount_a[length - 2];
	
}

int main() {
	const char str_a[] = "aba",
		   length = sizeof(str_a) / sizeof(char) - 1;
	return 0;
}