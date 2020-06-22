#include "include_all.h"

bool patternMatching(char pat_str_a[], char obj_str_a[]) {
	unsigned a_amount = 0, b_amount = 0;
	unsigned obj_length = strlen(obj_str_a);
	int first_a_index = obj_length, first_b_index = obj_length;
	for (const char* pat_p = pat_str_a;; pat_p++) {
		char pat = *pat_p;
		if (pat == '\0') {
			break;
		} else if (pat == 'a') {
			a_amount++;
			if (first_a_index == obj_length) {
				first_a_index = pat_p - pat_str_a;
			}
		} else {
			b_amount++;
			if (first_b_index == obj_length) {
				first_b_index = pat_p - pat_str_a;
			}
		}
	}
	unsigned a_length = 0, a_total_length = 0, b_length, b_total_length;
	while (1) {
		b_total_length = (obj_length - a_length);
	}
}