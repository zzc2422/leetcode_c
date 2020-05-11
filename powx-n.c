double myPow(double x, int in) {
	unsigned n;
	if (in < 0) {
		x = 1 / x;
		n = -(unsigned)in;
	} else {
		n = in;
	}
	double xi = x, result = 1;
	while (1) {
		unsigned bit = n & 1;
		if (bit != 0) {
			result *= xi;
		}
		if (n == bit) {
			break;
		}
		n >>= 1;
		xi *= xi;
	}
	return result;
}