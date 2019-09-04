#include "include_all.h"

static char _is_prime(int n, int* prime_start_p, int* prime_end_np) {
	for (const int* p = prime_start_p; p != prime_end_np; p++) {
		int d = *p;
		if (n % d == 0) {
			return 0;
		}
	}
	return 1;
}

int countPrimes(int n) {
	// 若n过小，特殊处理
	if (n <= 2) {
		return 0;
	}
	// 定义素数栈，sp为栈顶指针（指向栈顶元素）
	int prime_stack_a[n], *snp = prime_stack_a;
	int i = 2, *max_divide_np = prime_stack_a, max_divide_n_until_n = 4;
	do {
		if (i == max_divide_n_until_n) {
			max_divide_np++;
			int max_divide_n = *max_divide_np;
			max_divide_n_until_n = max_divide_n * max_divide_n;
		} else if (_is_prime(i, prime_stack_a, max_divide_np)) {
			*snp = i;
			snp++;
		}
		i++;
	} while (i != n);
	return (int)(snp - prime_stack_a);
}