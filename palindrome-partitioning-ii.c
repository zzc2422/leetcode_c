// 未完成

#include "include_all.h"
#include <stdio.h>

static const char *_get_end_np(const char str_a[]) {
	const char *p;
	for (p = str_a; *p != '\0'; p++)
		;
	return p;
}

// 注意：字符串不能为空串
static void _kmp_next(int next_a[], int yes_next_a[], const char str_a[],
		      int length) {
	next_a[0] = yes_next_a[0] = -1;
	if (length == 1) {
		return;
	}
	int next = 0;
	for (int next_i = 1, sub_i = 0;; next_i++, sub_i++, next = sub_i) {
		yes_next_a[next_i] = next;
		char ch = str_a[next_i], sub = str_a[sub_i];
		if (ch == sub) {
			next = next_a[next];
		}
		next_a[next_i] = next;
		if (next_i == length) {
			return;
		}
		while (ch != sub) {
			sub_i = next_a[sub_i];
			if (sub_i < 0) {
				break;
			}
			sub = str_a[sub_i];
		}
	}
}

// palin_end_npa为可以使成为回文串的终点（不含）数组。注意：字符串长度至少为2。
static const int *_inverse_match(int palin_len_a[], const char *start_p,
				 const char *end_np, const int next_a[],
				 const int yes_next_a[]) {
	int *sp = palin_len_a;
	const char *rp = end_np - 1;
	int palin_len_m1 = rp - start_p, li = 0;
	char r = *rp;
	while (1) {
		while (r != start_p[li]) {
			li = next_a[li];
			palin_len_m1 = rp + li - start_p;
			if (li < 0) {
				break;
			}
		}
		if (((li + 1) << 1) < palin_len_m1) {
			li++;
			rp--;
			r = *rp;
			continue;
		}
		*sp = palin_len_m1 + 1;
		sp++;
		if (palin_len_m1 == 0) {
			return sp;
		}
		li = yes_next_a[li];
	}
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
	// cut_times_a[i]表示从str_a[i + 1]开始之后的串分割次数
	int seg_amount_a[length - 2], next_a[length], yes_next_a[length],
		palin_len_a[length];
	for (const char *start_p = end_np - 2;; start_p--) {
		_kmp_next(next_a, yes_next_a, start_p, end_np - start_p);
		const int *pl_end_np = _inverse_match(
			palin_len_a, start_p, end_np, next_a, yes_next_a);
		int seg_amount =
			_seg_amount(start_p, end_np, palin_len_a, pl_end_np,
				    seg_amount_a + (start_p - str_a));
		if (start_p == str_a) {
			return seg_amount;
		}
	}
}