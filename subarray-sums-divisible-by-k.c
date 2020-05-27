#include "include_all.h"

int subarraysDivByK(int a[], int length, int k) {
	int sum_mod = 0, amount = 0;
	const int* p = a;
	unsigned mod_a[k];
	mod_a[0] = 1;
	memset(mod_a + 1, 0, sizeof(unsigned[k - 1]));
	do {
		sum_mod = (sum_mod + *p) % k;
		if (sum_mod < 0) {
			sum_mod += k;
		}
		unsigned* mod_p = mod_a + sum_mod;
		int mod = *mod_p;
		amount += mod;
		*mod_p = mod + 1;
		p++;
	} while (p != a + length);
	return amount;
}