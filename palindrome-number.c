#include "include_all.h"

bool isPalindrome(int x) {
	if (x < 0 || (x != 0 && x % 10 == 0)) {
		return false;
	}
	int rev = 0;
	while (1) {
		int bit = x % 10;
		x /= 10;
		if (x == rev) {
			return true;
		} else if (x < rev) {
			return false;
		}
		rev = rev * 10 + bit;
		if (x == rev) {
			return true;
		} else if (x < rev) {
			return false;
		}
	}
}