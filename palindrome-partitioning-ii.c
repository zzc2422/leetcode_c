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

// 注意：字符串长度至少为2
static int _inverse_match(int match_ia[], const char *start_p,
			  const char *end_np, const int next_a[],
			  const int yes_next_a[]) {
	int *sp = match_ia;
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
		int palin_ni = (int)(palin_end_p - start_p + 1);
		*sp = palin_ni;
		sp++;
		if (palin_end_p == start_p) {
			return (int)(sp - match_ia);
		}
		li = next_a[li];
	}
}

int minCut(const char str_a[]) {
	const char *end_np = _get_end_np(str_a);
	if (end_np <= str_a + 1) {
		return 1;
	}
	int length = end_np - str_a;
	int cut_times_a[length - 1];
	cut_times_a[length - 2] = 1;
	int next_a[length], yes_next_a[length], match_ia[length - 1];
	_kmp_next(next_a, yes_next_a, str_a, length);
	
}