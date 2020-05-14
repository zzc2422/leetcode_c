int singleNumber(int a[], int length) {
	unsigned all_xor = 0;
	for (const int* p = a; p != a + length; p++) {
		all_xor ^= *p;
	}
	return all_xor;
}