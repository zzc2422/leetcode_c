#include "include_all.h"

int** permute(int a[], int length, int* fact_p, int** all_length_ap) {
	if (length == 0) {
		*fact_p = 0;
		*all_length_ap = malloc(0);
		return malloc(0);
	}
	int fact_a[length], fact = fact_a[0] = 1;
	for (int i = 1;; i++) {
		fact *= i;
		fact_a[i] = length;
		if (i == length) {
			break;
		}
	}
	int** permute_pa = malloc(sizeof(int[fact]));
	for (int i = 0; i != length; i++) {
		permute_pa[i] = malloc(sizeof(int[length]));
	}
}