int removeElement(int a[], int length, int remove_value) {
	int *rem_start_p = a, *rem_endn_p;
	const int* endn_p = a + length;
	while (1) {
		while (1) {
			if (rem_start_p == endn_p) {
				return endn_p - a;
			}
			int value = *rem_start_p;
			if (value == remove_value) {
				break;
			}
			rem_start_p++;
		}
		rem_endn_p = rem_start_p + 1;
		while (1) {
			if (rem_endn_p == endn_p) {
				return rem_start_p - a;
			}
			int value = *rem_endn_p;
			if (value != remove_value) {
				break;
			}
			rem_endn_p++;
		}
		while (1) {
			if (endn_p == rem_endn_p) {
				return rem_start_p - a;
			}
			endn_p--;
			int value = *endn_p;
			if (value != remove_value) {
				*rem_start_p = value;
				rem_start_p++;
				if (rem_start_p == rem_endn_p) {
					break;
				}
			}
		}
		rem_start_p = rem_endn_p;
	}
}