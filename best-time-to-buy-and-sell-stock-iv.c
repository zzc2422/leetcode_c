int maxProfit(int max_times, int price_a[], int length) {
	int space_a[length];
	int *max_a = space_a, *min_a = space_a + length / 2;
	const int *p = price_a, *endn_p = price_a + length;
	int min = *p, index = 0;
	while (1) {
		p++;
		if (p >= endn_p) {
			break;
		}
		int p_value = *p, max;
		if (p_value <= min) {
			min = p_value;
			continue;
		}
		do {
			max = p_value;
			p++;
			if (p == endn_p) {
				break;
			}
			p_value = *p;
		} while (p_value >= max);
		max_a[index] = max;
		min_a[index] = min;
		index++;
	}
}