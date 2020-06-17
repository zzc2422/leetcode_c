int divide(int dividend, int divisor) {
	int sign = 0;
	unsigned result = 0;
	if (dividend < 0) {
		dividend = -(unsigned)dividend;
		sign = !sign;
	}
	if (divisor < 0) {
		divisor = -(unsigned)divisor;
		sign = !sign;
	}
	unsigned dividend_sub = dividend, divisor_move = divisor;
	while (divisor_move < dividend_sub) {
		divisor_move <<= 1;
	}
	while (divisor_move >= divisor) {
		result <<= 1;
		if (dividend_sub >= divisor_move) {
			dividend_sub -= divisor_move;
			result++;
		}
		divisor_move >>= 1;
	}
	if (sign) {
		result = -result;
	}
	return result;
}