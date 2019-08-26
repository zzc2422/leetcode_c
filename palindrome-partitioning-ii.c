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
static const char **_inverse_match(const char *palin_end_npa[],
				   const char *start_p, const char *end_np,
				   const int next_a[], const int yes_next_a[]) {
	const char **sp = palin_end_npa;
	const char *palin_end_p = end_np - 1, *rp = palin_end_p;
	char r = *rp;
	int li = 0;
	while (1) {
		while (r != start_p[li]) {
			li = next_a[li];
			palin_end_p = rp + li;
			if (li < 0) {
				break;
			}
		}
		if (start_p + ((li + 1) << 1) < palin_end_p) {
			li++;
			rp--;
			r = *rp;
			continue;
		}
		*sp = palin_end_p + 1;
		sp++;
		if (palin_end_p == start_p) {
			return sp;
		}
		li = yes_next_a[li];
	}
}

static int _seg_amount(int seg_amount_a[], const char str_a[], int length) {
	
}

int minCut(const char str_a[]) {
	const char *end_np = _get_end_np(str_a);
	if (end_np <= str_a + 1) {
		return 1;
	}
	int length = end_np - str_a;
	// cut_times_a[i]表示从str_a[i]开始之后的串分割次数
	int seg_amount_a[length - 1];
}

/*



























*/