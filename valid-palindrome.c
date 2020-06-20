#include "include_all.h"

static char _tran(char c) {
	if (c >= 'A' && c <= 'Z') {
		c += 'a' - 'A';
	}
	return c;
}

static unsigned _is_valid(char c) {
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
	       (c >= '0' && c <= '9');
}

bool isPalindrome(char str_a[]) {
	unsigned length = strlen(str_a);
	const char *left_p = str_a - 1, *right_p = str_a + length;
	while (1) {
		char left_c;
		while (1) {
			if (left_p == right_p) {
				return true;
			}
			left_p++;
			left_c = *left_p;
			if (_is_valid(left_c)) {
				break;
			}
		}
		left_c = _tran(left_c);
		char right_c;
		while (1) {
			if (left_p == right_p) {
				return true;
			}
			right_p--;
			right_c = *right_p;
			if (_is_valid(right_c)) {
				break;
			}
		}
		right_c = _tran(right_c);
		if (left_c != right_c) {
			return false;
		}
	}
}