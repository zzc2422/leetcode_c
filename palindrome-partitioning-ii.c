// 未完成

#include "include_all.h"
#include <stdio.h>

static const char *_get_end_np(const char str_a[]) {
	const char *p;
	for (p = str_a; *p != '\0'; p++)
		;
	return p;
}

// 注意：str长度至少为2
static const int *_pl_end_np(const char *str_start_p, const char *str_end_np,
			     int *pl_start_p, const int *pl_end_np) {
	char first_char = str_start_p[0];
	const int *inp = pl_start_p;
	int *outp = pl_start_p;
	do {
		int palin_len = *inp;
		const char *palin_end_np = str_start_p + 1 + palin_len;
		if (palin_end_np != str_end_np && *palin_end_np == first_char) {
			*outp = palin_len + 2;
			outp++;
		}
		inp++;
	} while (inp != pl_end_np);
	if (str_start_p[1] == first_char) {
		*outp = 2;
		outp++;
	}
	*outp = 1;
	return outp + 1;
}

int minCut(const char str_a[]) {
	const char *end_np = _get_end_np(str_a);
	if (end_np <= str_a + 1) {
		return 0;
	}
	int length = end_np - str_a;
	// cut_times_a[i]表示从str_a[i + 1]开始之后的串分割次数
	int cut_amount_a[length], palin_len_a[length];
	cut_amount_a[length - 1] = -1;
	palin_len_a[0] = 1;
	const int *pl_end_np = palin_len_a + 1;
	for (const char *start_p = end_np - 2;; start_p--) {
		size_t sa_offset = start_p - str_a - 1;
		int min_cut_amount = end_np - start_p;
		pl_end_np = _pl_end_np(start_p, end_np, palin_len_a, pl_end_np);
		const int *p = palin_len_a;
		do {
			int palin_len = *p, cut_amount;
			cut_amount = cut_amount_a[palin_len + sa_offset] + 1;
			if (cut_amount < min_cut_amount) {
				min_cut_amount = cut_amount;
			}
			p++;

		} while (p != pl_end_np);
		if (start_p == str_a) {
			return min_cut_amount;
		}
		cut_amount_a[sa_offset] = min_cut_amount;
	}
}

int main() {
	const char str_a[] = "abacabaabac";
	int min_seg_amount = minCut(str_a);
	printf("%d\n", min_seg_amount);
	return 0;
}