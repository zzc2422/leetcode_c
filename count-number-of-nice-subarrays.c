int numberOfSubarrays(int a[], int length, int k) {
	int odd_gap_a[length + 1];
	const int *p = a, *endn_p = a + length;
	int* op = odd_gap_a;
	int odd_gap = 1;
	while (1) {
		if (p == endn_p || (*p) & 1) {
			*op = odd_gap;
			odd_gap = 1;
			op++;
		} else {
			odd_gap++;
		}
		if (p == endn_p) {
			break;
		}
		p++;
	}
	const int* og_endn_p = op;
	if (og_endn_p < odd_gap_a + k + 1) {
		return 0;
	}
	const int *left_p = odd_gap_a, *right_p = left_p + k;
	int sum = 0;
	while (right_p != og_endn_p) {
		sum += (*left_p) * (*right_p);
		left_p++;
		right_p++;
	}
	return sum;
}