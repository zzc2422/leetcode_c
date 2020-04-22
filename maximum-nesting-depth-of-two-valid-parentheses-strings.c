#include "include_all.h"

int* maxDepthAfterSplit(char str_a[], int* length_p) {
	int length = strlen(str_a);
	*length_p = length;
	int* result_a = malloc(sizeof(int[length]));
	int depth0 = 0, depth1 = 0;
	for (int i = 0; i != length; i++) {
		if (str_a[i] == '(') {
			if (depth0 < depth1) {
				result_a[i] = 0;
				depth0++;
			} else {
				result_a[i] = 1;
				depth1++;
			}
		} else {
			if (depth0 < depth1) {
				result_a[i] = 1;
				depth1--;
			} else {
				result_a[i] = 0;
				depth0--;
			}
		}
	}
	return result_a;
}