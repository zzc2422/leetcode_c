#include "include_all.h"

int* dailyTemperatures(int a[], int length, int* length_p) {
	int* result_a = malloc(sizeof(int[length]));
	*length_p = length;
	int stack_a[length], *sp = stack_a;
	int index = 0;
	do {
		int value = a[index];
		while (sp != stack_a) {
			int pre_index = sp[-1], pre_value = a[pre_index];
			if (value <= pre_value) {
				break;
			}
			result_a[pre_index] = index - pre_index;
			sp--;
		}
		*sp = index;
		sp++;
		index++;
	} while (index != length);
	for (int i = 0; stack_a + i != sp; i++) {
		index = stack_a[i];
		result_a[index] = 0;
	}
	return result_a;
}