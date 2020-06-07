int trap(int height_a[], int length) {
	if (length == 0) {
		return 0;
	}
	int left_max_a[length], right_max_a[length], length_m1 = length - 1;
	int i = 0, max = height_a[0];
	while (1) {
		left_max_a[i] = max;
		if (i == length_m1) {
			break;
		}
		i++;
		int value = height_a[i];
		if (value > max) {
			max = value;
		}
	}
	max = height_a[length_m1];
	while (1) {
		right_max_a[i] = max;
		if (i == 0) {
			break;
		}
		i--;
		int value = height_a[i];
		if (value > max) {
			max = value;
		}
	}
	int total = 0;
	do {
		int left_max = left_max_a[i], right_max = right_max_a[i];
		int out_min = (left_max > right_max ? right_max : left_max);
		int height = height_a[i], com = out_min - height;
		if (com > 0) {
			total += com;
		}
		i++;
	} while (i != length);
	return total;
}