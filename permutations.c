#include "include_all.h"

int* findDiagonalOrder(int* row_pa[], int row_amount, int row_length_a[],
		       int* total_p) {
	int total = 0;
	for (int i = 0; i != row_amount; i++) {
		total += row_length_a[i];
	}
	*total_p = total;
	int *result_a = malloc(sizeof(int[total])), *p_out = result_a;
	int next_row_a[row_amount + 1];
	for (int i = row_amount;;) {
		i--;
		next_row_a[i + 1] = i;
		if (i < 0) {
			break;
		}
	}
	for (int sum = 0;; sum++) {
		int prev_row = sum;
		if (prev_row > row_amount) {
			prev_row = row_amount;
		}
		int row = next_row_a[prev_row];
		if (row < 0) {
			break;
		}
		while (1) {
			int column = sum - row;
			int next_row = next_row_a[row];
			if (column < row_length_a[row]) {
				*p_out = row_pa[row][column];
				p_out++;
			} else {
				next_row_a[prev_row] = next_row;
			}
			if (next_row < 0) {
				break;
			}
			prev_row = row;
			row = next_row;
		}
	}
	return result_a;
}