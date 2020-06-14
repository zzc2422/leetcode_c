#include "include_all.h"

static int _get_max_common_length(char* str_ba[], int str_amount) {
	int i = 0;
	const char* first_str_a = str_ba[0];
	while (1) {
		char first_str_c = first_str_a[i];
		if (first_str_c == '\0') {
			return i;
		}
		char* const* str_bp = str_ba + 1;
		while (str_bp != str_ba + str_amount) {
			char c = (*str_bp)[i];
			if (c != first_str_c) {
				return i;
			}
			str_bp++;
		}
		i++;
	}
}

char* longestCommonPrefix(char* str_ba[], int str_amount) {
	char* result_a;
	int max_common_length;
	if (str_amount == 0) {
		max_common_length = 0;
		result_a = malloc(sizeof(char));
	} else {
		max_common_length = _get_max_common_length(str_ba, str_amount);
		result_a = malloc(sizeof(char[max_common_length + 1]));
		memcpy(result_a, str_ba[0], sizeof(char[max_common_length]));
	}
	result_a[max_common_length] = '\0';
	return result_a;
}