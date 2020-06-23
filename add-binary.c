#include "include_all.h"

char* addBinary(char n1_a[], char n2_a[]) {
	unsigned length1 = strlen(n1_a), length2 = strlen(n2_a);
	if (length1 < length2) {
		char* tmp_p = n1_a;
		n1_a = n2_a;
		n2_a = tmp_p;
		unsigned tmp = length1;
		length1 = length2;
		length2 = tmp;
	}
	const char *n1_p = n1_a + length1, *n2_p = n2_a + length2;
	char tmp_a[length1 + 1], *tmp_p = tmp_a + length1, cap = 0;
	do {
		n1_p--, n2_p--;
		char num1 = *n1_p - '0', num2 = *n2_p - '0';
		char sum = num1 + num2 + cap;
		if (sum > 1) {
			cap = 1;
			sum -= 2;
		} else {
			cap = 0;
		}
		*tmp_p = sum + '0';
		tmp_p--;
	} while (n2_p != n2_a);
	while (n1_p != n1_a) {
		n1_p--;
		char num1 = *n1_p - '0';
		char sum = num1 + cap;
		if (sum > 1) {
			cap = 1;
			sum -= 2;
		} else {
			cap = 0;
		}
		*tmp_p = sum + '0';
		tmp_p--;
	}
	if (cap != 0) {
		*tmp_p = cap + '0';
	} else {
		tmp_p++;
	}
	unsigned result_length = (tmp_a + length1 + 1) - tmp_p;
	char* result_a = malloc(sizeof(char[result_length + 1]));
	memcpy(result_a, tmp_p, sizeof(char[result_length]));
	result_a[result_length] = '\0';
	return result_a;
}