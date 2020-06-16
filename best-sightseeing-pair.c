int maxScoreSightseeingPair(int a[], int length) {
	int left_select = 0, left_score = a[0], max_total = left_score;
	for (int i = 1; i != length; i++) {
		int score = a[i], total = left_score + score + left_select - i;
		if (total > max_total) {
			max_total = total;
		}
		if (score > left_score + left_select - i) {
			left_select = i;
			left_score = score;
		}
	}
	return max_total;
}