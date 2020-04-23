#include "include_all.h"

int waysToChange(int n) {
	const unsigned MOD = 1000000007;
	n -= n % 5;
	unsigned ta_a[5] = {0, 0, 0, 0};
	unsigned* p = ta_a + 4;
	unsigned maxle5 = 1, maxle10 = 1, maxle25 = 1;
	unsigned maxle10p5 = 0, maxle10p10 = 0;
	while (n != 0) {
		*p = maxle25;
		unsigned max1 = 1;
		unsigned max5 = maxle5;
		maxle5 = max1 + max5;
		if (maxle5 >= MOD) {
			maxle5 -= MOD;
		}
		maxle10p10 = maxle10p5;
		maxle10p5 = maxle10;
		unsigned max10 = maxle10p10;
		maxle10 = maxle5 + max10;
		if (maxle10 >= MOD) {
			maxle10 -= MOD;
		}
		p++;
		if (p >= ta_a + 5) {
			p = ta_a;
		}
		unsigned totalp25 = *p;
		unsigned max25 = totalp25;
		maxle25 = maxle10 + max25;
		if (maxle25 >= MOD) {
			maxle25 -= MOD;
		}
		n -= 5;
	}
	return maxle25;
}