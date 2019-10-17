#include "include_all.h"

void rotate(int* matrix_aa[], int length, const int no_use[]) {
	for (int left_up = 0, right_down = length - 1; left_up < right_down;
	     left_up++, right_down--) {
		for (int i = left_up, inv_i = length - 1; i != right_down;
		     i++, inv_i--) {
			int *up_p = matrix_aa[left_up] + i,
			    *left_p = matrix_aa[inv_i] + left_up,
			    *down_p = matrix_aa[right_down] + inv_i,
			    *right_p = matrix_aa[i] + right_down;
			int tmp = *up_p;
			*up_p = *left_p;
			*left_p = *down_p;
			*down_p = *right_p;
			*right_p = tmp;
		}
	}
}