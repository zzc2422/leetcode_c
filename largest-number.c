#include <stdlib.h>

typedef struct {
	unsigned n, all9;
} ul_t;

static unsigned _get_all9(unsigned n) {
	unsigned i = 10;
	while (1) {
		n /= 10;
		if (n == 0) {
			break;
		}
		i *= 10;
	}
	return i - 1;
}

static void _init_ul(ul_t* ul_p, unsigned n) {
	ul_p->n = n;
	ul_p->all9 = _get_all9(n);
}

static int _cmp_21g12p(const void* p1, const void* p2) {
	const ul_t *ul1p = (const ul_t*)p1, *ul2p = (const ul_t*)p2;
	long long unsigned n1 = ul1p->n, n2 = ul2p->n;
	long long unsigned l1 = ul1p->all9, l2 = ul2p->all9;
	long long unsigned n1l2 = n1 * l2, n2l1 = n2 * l1;
	if (n2l1 > n1l2) {
		return 1;
	} else if (n1l2 > n2l1) {
		return -1;
	} else {
		return 0;
	}
}

static void _write_str(char** pp, ul_t ul) {
	unsigned n = ul.n, index = ul.all9 + 1;
	char* p = *pp;
	while (1) {
		index /= 10;
		if (index == 0) {
			break;
		}
		unsigned top = n / index;
		n %= index;
		*p = top + '0';
		p++;
	}
	*pp = p;
}

char* largestNumber(const int a[], int length) {
	ul_t ul_a[length];
	for (int i = 0; i != length; i++) {
		_init_ul(ul_a + i, a[i]);
	}
	qsort(ul_a, length, sizeof(ul_t), _cmp_21g12p);
	char *str_a = malloc(length * 10 + 1), *p = str_a;
	for (int i = 0; i != length; i++) {
		_write_str(&p, ul_a[i]);
	}
	if (str_a[0] == '0') {
		str_a[1] = '\0';
	} else {
		*p = '\0';
	}
	return str_a;
}