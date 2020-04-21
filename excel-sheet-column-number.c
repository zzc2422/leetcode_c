#include "include_all.h"

int titleToNumber(char s[]) {
	int sum = 0;
	while (1) {
		char c = *s;
		if (c == '\0') {
			break;
		}
		int value = c - 'A' + 1;
		sum = sum * 26 + value;
		s++;
	}
	return sum;
}