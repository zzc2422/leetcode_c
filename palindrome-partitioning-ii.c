#include "include_all.h"
#include <stdio.h>

static int get_length(const char str_a[]) {
	const char *p;
	for (p = str_a; *p != '\0'; p++)
		;
	return (int)(p - str_a);
}

// 注意：字符串不能为空串
static int _kmp_next(int next_a[], const char ch_a[], int length) {
	next_a[0] = -1;
	int next = 0;
	for (int next_i = 1, sub_i = 0; next_i != length;
	     next_i++, sub_i++, next = sub_i) {
		char ch = ch_a[next_i], sub = ch_a[sub_i];
		if (ch == sub) {
			next = next_a[next];
		}
		while (ch != sub) {
			sub_i = next_a[sub_i];
			if (sub_i < 0) {
				break;
			}
			sub = ch_a[sub_i];
		}
		next_a[next_i] = next;
	}
	return next;
}

int minCut(const char str[]) {
}