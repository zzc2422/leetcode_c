int translateNum(int num) {
	unsigned prev_bit = num % 10, prev_amount = 1, amount = 1;
	while (1) {
		num /= 10;
		if (num == 0) {
			break;
		}
		unsigned bit = num % 10;
		unsigned amount_backup = amount;
		if (bit == 1 || (bit == 2 && prev_bit <= 5)) {
			amount += prev_amount;
		}
		prev_bit = bit;
		prev_amount = amount_backup;
	}
	return amount;
}