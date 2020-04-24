#include <stdio.h>

typedef unsigned int u32;
typedef unsigned char u8;

void print_u32_hex(u32 n, u32 min_hexbit_amount) {
	static const u8 bit_show_a[] = {'0', '1', '2', '3', '4', '5', '6', '7',
					'8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	u32 t = min_hexbit_amount << 2;
	u32 right_bit_amount = 28;
	while (1) {
		u32 bit4 = (n >> right_bit_amount) & 15;
		if (bit4 != 0 || right_bit_amount < t) {
			u32 hexbit = bit_show_a[bit4];
			putchar(hexbit);
		}
		if (right_bit_amount == 0) {
			break;
		}
		right_bit_amount -= 4;
	}
}

int main() {
	print_u32_hex(0, 7777);
	putchar('\n');
	return 0;
}
/*








































*/