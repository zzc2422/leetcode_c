int canCompleteCircuit(const int gas_a[], int no_use, const int cost_a[],
		       int length) {
	int rest = 0, min_rest = 0, i = 0, min_i = 0;
	do {
		rest += gas_a[i] - cost_a[i];
		if (rest < min_rest) {
			min_rest = rest;
			min_i = i;
		}
		i++;

	} while (i != length);
	return rest >= 0 ? min_i : -1;
}