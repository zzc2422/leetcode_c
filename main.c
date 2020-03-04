#include <stdio.h>

char* largestNumber(const int a[], int length);

int main() {
	int a[] = {0, 0};
	puts(largestNumber(a, sizeof(a) / sizeof(int)));
	return 0;
}