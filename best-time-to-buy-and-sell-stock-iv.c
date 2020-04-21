#include <memory.h>

static unsigned _max_profit(const unsigned positive_a[],
			    const unsigned negative_a[], unsigned length,
			    unsigned max_times) {
	unsigned sum_a[length], sum = 0;
	memset(sum_a, 0, sizeof(unsigned[length]));
	if (max_times > length) {
		max_times = length;
	}
	unsigned times = 0, sum_head = 0;
	while (times != max_times) {
		sum_head += positive_a[times];
		unsigned cur = sum = sum_head;
		unsigned sum_pre;
		unsigned day = times;
		while (1) {
			sum_pre = sum_a[day];
			sum_a[day] = sum;
			day++;
			if (day == length) {
				break;
			}
			int price = cur - negative_a[day];
			if (price < (int)sum_pre) {
				price = sum_pre;
			}
			cur = price + positive_a[day];
			if (cur > sum) {
				sum = cur;
			}
		}
		times++;
	}
	return sum;
}

int maxProfit(int max_times, int price_a[], int length) {
	if (length == 0) {
		return 0;
	}
	int max, min, p_value;
	const int *p = price_a, *endn_p = price_a + length;
	max = min = *p;
	unsigned space_a[length], index = 0;
	unsigned *positive_a = space_a, *negative_a = space_a + (length >> 1);
	while (1) {
		p++;
		if (p >= endn_p) {
			break;
		}
		p_value = *p;
		if (p_value <= min) {
			min = p_value;
			continue;
		}
		negative_a[index] = max - min;
		while (1) {
			max = p_value;
			p++;
			if (p == endn_p) {
				break;
			}
			p_value = *p;
			if (p_value < max) {
				break;
			}
		}
		positive_a[index] = max - min;
		min = p_value;
		index++;
	}
	if (index == 0) {
		return 0;
	}
	return _max_profit(positive_a, negative_a, index, max_times);
}