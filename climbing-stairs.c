int climbStairs(int n) {
	if (n <= 1) {
		return 1;
	}
	int amount = 1, prev_amount = 1, current = 1;
	do {
		current++;
		int new_amount = amount + prev_amount;
		prev_amount = amount;
		amount = new_amount;
	} while (current != n);
	return amount;
}