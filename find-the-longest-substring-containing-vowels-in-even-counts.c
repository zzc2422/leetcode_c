static int _is_aeiou(char c) {
	switch (c) {
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		return 1;
	default:
		return 0;
	}
}

int findTheLongestSubstring(char str_a[]) {
	const char* p;
	for (p = str_a;; p++) {
		char c = *p;
		if (c == '\0') {
			return (p - str_a);
		} else if (_is_aeiou(c)) {
			break;
		}
	}
	unsigned even = 0, s_even = p - str_a, odd = even + 1;
	while (1) {
		p++;
		char c = *p;
		if (c == '\0') {
			break;
		} else if (_is_aeiou(c)) {
			int new_even = odd + 1;
			int new_odd = even + 1;
			even = new_even;
			odd = new_odd;
		} else {
			even++;
			odd++;
		}
		if (even > s_even) {
			s_even = even;
		}
	}
	return s_even;
}