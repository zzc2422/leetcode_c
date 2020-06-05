#include "include_all.h"

int* spiralOrder(int** matrix_aa, int row_amount, int column_size_a[],
		 int* size_p) {
	if (row_amount == 0) {
		*size_p = 0;
		return malloc(0);
	}
	int coluomn_amount = column_size_a[0];
	int size = row_amount * coluomn_amount;
	*size_p = size;
	int *result_a = malloc(sizeof(int[size])), *sp = result_a;
	int up = 0, down = row_amount - 1, left = 0, right = coluomn_amount - 1;
	while (1) {
		// 输出最上行
		int i = left;
		do {
			*sp = matrix_aa[up][i];
			sp++;
			i++;
		} while (i <= right);
		if (up == down) {
			break;
		}
		up++;
		// 输出最右列
		i = up;
		do {
			*sp = matrix_aa[i][right];
			sp++;
			i++;
		} while (i <= down);
		if (right == left) {
			break;
		}
		right--;
		// 输出最下行
		i = right;
		do {
			*sp = matrix_aa[down][i];
			sp++;
			i--;
		} while (i >= left);
		if (down == up) {
			break;
		}
		down--;
		// 输出最左列
		i = down;
		do {
			*sp = matrix_aa[i][left];
			sp++;
			i--;
		} while (i >= up);
		if (left == right) {
			break;
		}
		left++;
	}
	return result_a;
}