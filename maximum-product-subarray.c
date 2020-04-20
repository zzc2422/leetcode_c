int maxProduct(const int a[], int length) {
	int with_max = a[0], with_min = with_max;
	int global_max = with_max;
	const int *p = a, *endn_p = a + length;
	while (1) {
		p++;
		if (p == endn_p) {
			return global_max;
		}
		int value = *p;
		int mul1 = with_max * value, mul2 = with_min * value;
		if (mul1 > mul2) {
			with_max = mul1;
			with_min = mul2;
		} else {
			with_max = mul2;
			with_min = mul1;
		}
		if (value > with_max) {
			with_max = value;
		} else if (value < with_min) {
			with_min = value;
		}
		if (with_max > global_max) {
			global_max = with_max;
		}
	}
}