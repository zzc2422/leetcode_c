double new21Game(int N, int K, int W) {
	int n = N - K + 1;
	if (n >= W) {
		return 1;
	}
	double k_start_prob_a[W];
	double* spendn_p = k_start_prob_a + W;
	double* dp = k_start_prob_a;
	for (; dp < k_start_prob_a + n; dp++) {
		*dp = 1;
	}
	for (; dp < spendn_p; dp++) {
		*dp = 0;
	}
	int start = K;
	double sum = n;
	while (1) {
		start--;
		dp--;
		double prob = sum / W;
		sum -= *dp;
		if (start == 0) {
			return prob;
		}
		sum += prob;
		*dp = prob;
		if (dp == k_start_prob_a) {
			dp = spendn_p;
		}
	}
}