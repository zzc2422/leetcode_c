int search(int a[], int length, int target) {
	const int* start_a = a;
	if (length == 0) {
		return -1;
	}
	int left_value = a[0];
	while (length != 1) {
		int right_length = (length >> 1);
		int left_length = length - right_length;
		int right_start_value = start_a[left_length];
		int b1 = (left_value < right_start_value);
		int b2 = (target < left_value);
		int b3 = (target < right_start_value);
		if (b1 ^ b2 ^ b3) {
			start_a += left_length;
			left_value = right_start_value;
			length = right_length;
		} else {
			length = left_length;
		}
	}
	if (*start_a == target) {
		return start_a - a;
	} else {
		return -1;
	}
}