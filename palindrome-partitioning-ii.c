#include "include_all.h"
#include <stdio.h>

static int _get_length(const char str_a[]) {
	const char *p;
	for (p = str_a; *p != '\0'; p++)
		;
	return (int)(p - str_a);
}

// 注意：字符串不能为空串
static int _kmp_next(int next_a[], const char str_a[], int length) {
	next_a[0] = -1;
	int next = 0;
	for (int next_i = 1, sub_i = 0; next_i != length;
	     next_i++, sub_i++, next = sub_i) {
		char ch = str_a[next_i], sub = str_a[sub_i];
		if (ch == sub) {
			next = next_a[next];
		}
		while (ch != sub) {
			sub_i = next_a[sub_i];
			if (sub_i < 0) {
				break;
			}
			sub = str_a[sub_i];
		}
		next_a[next_i] = next;
	}
	return next;
}

// 注意：字符串长度至少为2
static int _inverse_match(int match_a[], const char str_a[], const int next_a[],
			  int length, int end_next) {
	
}

int minCut(const char str_a[]) {
	int length = _get_length(str_a);
	if (length <= 1) {
		return 1;
	}
	int cut_times_a[length - 1];
	cut_times_a[length - 2] = 1;
	int next_a[length], match_ia[length - 1];
	for (int sub_length = 2;; sub_length++) {
		int start_i = length - sub_length;
		int end_next = _kmp_next(next_a, str_a + start_i, sub_length);
	}
}