#include "include_all.h"

static int _str_to_int(const char str[]) {
	int number = 0;
	for (const char* p = str;; p++) {
		char c = *p;
		if (c == '\0') {
			return number;
		}
		int i = c - '0';
		number = number * 10 + i;
	}
}

int evalRPN(const char* const token_a[], int token_amount) {
	int stack_a[token_amount], *sp = stack_a;
	for (const char* const* pp = token_a; pp != token_a + token_amount;
	     pp++) {
		const char* str_a = *pp;
		char first = *str_a;
		switch (first) {
		case '*':
			sp--;
			*(sp - 1) *= *sp;
			break;
		case '/':
			sp--;
			*(sp - 1) /= *sp;
			break;
		case '+':
			sp--;
			*(sp - 1) += *sp;
			break;
		case '-':
			if (str_a[1] == '\0') {
				sp--;
				*(sp - 1) -= *sp;
			} else {
				*sp = -_str_to_int(str_a + 1);
				sp++;
			}
			break;
		default:
			*sp = _str_to_int(str_a);
			sp++;
		}
	}
	return *(sp - 1);
}