#include "include_all.h"

typedef struct {
	const int* int_p;
	int value;
} irpv_t;

static irpv_t _get_max_start_endn(const int* start_p, const int* endn_p) {
	const int* p = start_p;
	int max = *p, *max_p = p;
	while (1) {
		p++;
		if (p == endn_p) {
			break;
		}
		int value = *p;
		if (value > max) {
			max = value;
		}
	}
	irpv_t iwpv = {.int_p = max_p, .value = max};
	return iwpv;
}

static int* _malloc_int(int length) {
	return malloc(sizeof(int[length]));
}

int* maxSlidingWindow(int a[], int length, int k, int* return_size_p) {
	const int *win_start_p = a, *new_p = win_start_p + k;
	int return_size = length - k + 1;
	int* result_a = _malloc_int(return_size);
	*return_size_p = return_size;
	int* out_p = result_a;
	irpv_t max;
get_max:
	max = _get_max_start_endn(win_start_p, new_p);
	while (1) {
		*out_p = max.value;
		if (new_p == a + length) {
			break;
		}
		int new_value = *new_p;
		out_p++;
		win_start_p++;
		new_p++;
		if (max.int_p < win_start_p) {
			goto get_max;
		} else if (new_value >= max.value) {
			max.value = new_value;
			max.int_p = new_p;
		}
	}
	return result_a;
}