#include <stdio.h>

double* intersection(int l11_a[], int two1, int l12_a[], int two2, int l21_a[],
		     int two3, int l22_a[], int two4, int* length_p);

int main() {
	int line[2][2][2] = {{{0, 0}, {1, 1}}, {{-1, -1}, {3, 3}}};
	int length;
	intersection(line[0][0], 2, line[0][1], 2, line[1][0], 2, line[1][1], 2,
		     &length);
	return 0;
}
/*








































*/