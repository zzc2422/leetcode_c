#include "include_all.h"

static void _kmp(int next_a[], const char str_a[]) {
	next_a[0] = -1;
	int str_index = 0, sub_index = -1;
	char str_c = str_a[0], sub_c;
	goto in;
	while (1) {
		if (sub_index < 0 || (sub_c = str_a[sub_index]) == str_c) {
			str_index++;
			sub_index++;
			str_c = str_a[str_index];
			sub_c = str_a[sub_index];
			char next;
			if (str_c == sub_c) {
				next = next_a[sub_index];
			} else {
			in:
				next = sub_index;
			}
			next_a[str_index] = sub_index;
			if (str_c == '\0') {
				break;
			}
		} else {
			sub_index = next_a[sub_index];
		}
	}
}

int strStr(char str_a[], char sub_a[]) {
	int sub_length = strlen(sub_a);
	int next_a[sub_length + 1];
	_kmp(next_a, sub_a);
	int str_index = 0, sub_index = 0;
	char str_c = str_a[0];
	while (1) {
		char sub_c = sub_a[sub_index];
		if (sub_c == '\0') {
			return str_index - sub_length;
		} else if (str_c == '\0') {
			return -1;
		}
		if (str_c != sub_c) {
			sub_index = next_a[sub_index];
			if (sub_index >= 0) {
				continue;
			}
		}
		str_index++;
		str_c = str_a[str_index];
		sub_index++;
	}
}