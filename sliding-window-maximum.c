#include "include_all.h"

int* maxSlidingWindow(int a[], int length, int k, int* return_length_p) {
	const int *win_pa[length], *ow_p = a + k, *p = ow_p - 1, *max_p = p;
	const int **win_start_pp = win_pa + k - 1, **win_end_pp = win_start_pp;
	*win_start_pp = p;
	int max = *p;
	while (p != a) {
		p--;
		int value = *p;
		if (value > max) {
			max = value;
			max_p = p;
			win_start_pp--;
			*win_start_pp = p;
		}
	}
	int result_length = length - k + 1;
	int *result_a = malloc(sizeof(int[result_length])), *rp = result_a;
	*return_length_p = result_length;
	p = ow_p;
	while (1) {
		*rp = max;
		rp++;
		if (p == a + length) {
			break;
		} else if (p == max_p + k) {
			win_start_pp++;
		}
		int value = *p;
		while (win_end_pp >= win_start_pp) {
			int prev = **win_end_pp;
			if (value < prev) {
				break;
			}
			win_end_pp--;
		}
		win_end_pp++;
		*win_end_pp = p;
		p++;
		max_p = *win_start_pp;
		max = *max_p;
	}
	return result_a;
}