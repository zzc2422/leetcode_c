#include <stdlib.h>

unsigned reverseBits(unsigned n) {
	unsigned result = 0;
	for (int i = 0; i != 32; i++) {
		unsigned bit = n & 1;
		result = (result << 1) | bit;
		n >>= 1;
	}
	return result;
}