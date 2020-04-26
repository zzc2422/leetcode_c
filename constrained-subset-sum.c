#include "include_all.h"

typedef struct {
	const int* int_p;
	int value;
} irpv_t;

static irpv_t _get_max_start_endn(const int* start_p, const int* endn_p) {
	const int *p = start_p, *max_p = p;
	int max = *p;
	while (1) {
		p++;
		if (p == endn_p) {
			break;
		}
		int value = *p;
		if (value > max) {
			max = value;
			max_p = p;
		}
	}
	irpv_t irpv = {.int_p = max_p, .value = max};
	return irpv;
}

static irpv_t _get_max(const int a[], int length) {
	return _get_max_start_endn(a, a + length);
}

int constrainedSubsetSum(int a[], int length, int k) {
	int win_cp_a[k + 1], win_max = 0, global_max = INT_MIN;
	int* win_a = win_cp_a + 1;
	const int* win_max_p = win_cp_a;
	win_cp_a[0] = 0;
	int *win_p = win_a, *ap = a;
	while (1) {
		int value = *ap, sum = win_max + value;
		*win_p = sum;
		if (win_p == win_max_p) {
			irpv_t irpv = _get_max(win_cp_a, k + 1);
			win_max = irpv.value;
			win_max_p = irpv.int_p;
		} else if (sum > win_max) {
			win_max = sum;
			win_max_p = win_p;
		}
		if (sum > global_max) {
			global_max = sum;
		}
		ap++;
		if (ap == a + length) {
			break;
		}
		win_p++;
		if (win_p == win_a + k) {
			win_p = win_a;
		}
	}
	return global_max;
}
/*
























*/