#include "include_all.h"

int* twoSum(const int a[], int length, int target, int* two_p) {
	int* result_a = malloc(sizeof(int[2]));
	const int *left_p = a, *right_p = a + length - 1;
	int left_value = *left_p, right_value = *right_p;
	while (1) {
		int sum = left_value + right_value;
		if (sum == target) {
			result_a[0] = left_p - a + 1;
			result_a[1] = right_p - a + 1;
			break;
		} else if (sum > target) {
			right_p--;
			right_value = *right_p;
		} else {
			left_p++;
			left_value = *left_p;
		}
	}
	*two_p = 2;
	return result_a;
}