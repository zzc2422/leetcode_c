#include "include_all.h"

static int _is_between(int a1, int a2, int amin, int amax) {
	if (a1 <= a2) {
		return a1 <= amin && amax <= a2;
	} else {
		return a2 <= amin && amax <= a1;
	}
}

// 判断第三个数是否在前两个数之间
static int _is_i_between(int a1, int a2, int a) {
	return _is_between(a1, a2, a, a);
}

// 判断一个浮点数是否在两个给定整数之间
static int _is_d_between(int a1, int a2, double d) {
	if (d < 0) {
		d = -d;
		a1 = -a1;
		a2 = -a2;
	}
	int dmin = (int)d, dmax = dmin;
	if (d != dmin) {
		dmax++;
	}
	return _is_between(a1, a2, dmin, dmax);
}

static double* _return_cor(double x, double y, int* length_p) {
	double* inter_a = malloc(sizeof(double[2]));
	*length_p = 2;
	inter_a[0] = x;
	inter_a[1] = y;
	return inter_a;
}

static double* _return_null(int* length_p) {
	double* inter_a = malloc(0);
	*length_p = 0;
	return inter_a;
}

static double* _return_smaller(int x1, int y1, int x2, int y2, int* length_p) {
	if (x1 < x2) {
		return _return_cor(x1, y1, length_p);
	} else if (x1 > x2) {
		return _return_cor(x2, y2, length_p);
	} else if (y1 < y2) {
		return _return_cor(x1, y1, length_p);
	} else {
		return _return_cor(x2, y2, length_p);
	}
}

static double* _int_co(int x11, int y11, int x12, int y12, int x21, int y21,
		       int x22, int y22, int* length_p) {
	unsigned ylb = 0;
	if (x11 + y11 == x12 + y12) {
		ylb = 1;
	}
	int p11 = x11 + ((unsigned)y11 << ylb),
	    p12 = x12 + ((unsigned)y12 << ylb);
	int p21 = x21 + ((unsigned)y21 << ylb),
	    p22 = x22 + ((unsigned)y22 << ylb);
	int is_p11_in = _is_i_between(p21, p22, p11);
	int is_p12_in = _is_i_between(p21, p22, p12);
	int is_p21_in = _is_i_between(p11, p12, p21);
	int is_p22_in = _is_i_between(p11, p12, p22);
	if (is_p11_in && is_p12_in) {
		return _return_smaller(x11, y11, x12, y12, length_p);
	} else if (is_p11_in && is_p21_in) {
		return _return_smaller(x11, y11, x21, y21, length_p);
	} else if (is_p11_in && is_p22_in) {
		return _return_smaller(x11, y11, x22, y22, length_p);
	} else if (is_p12_in && is_p21_in) {
		return _return_smaller(x12, y12, x21, y21, length_p);
	} else if (is_p12_in && is_p22_in) {
		return _return_smaller(x12, y12, x22, y22, length_p);
	} else if (is_p21_in && is_p22_in) {
		return _return_smaller(x21, y21, x22, y22, length_p);
	} else {
		return _return_null(length_p);
	}
}

double* intersection(int l11_a[], int two1, int l12_a[], int two2, int l21_a[],
		     int two3, int l22_a[], int two4, int* length_p) {
	int x11 = l11_a[0], y11 = l11_a[1];
	int x12 = l12_a[0], y12 = l12_a[1];
	int x21 = l21_a[0], y21 = l21_a[1];
	int x22 = l22_a[0], y22 = l22_a[1];
	int dx1 = x12 - x11, dy1 = y12 - y11, dx2 = x22 - x21, dy2 = y22 - y21;
	int c1 = x11 * y12 - x12 * y11, d = dx1 * dy2 - dx2 * dy1;
	if (d != 0) {
		int c2 = x21 * y22 - x22 * y21;
		int d1 = dx1 * c2 - dx2 * c1, d2 = dy1 * c2 - dy2 * c1;
		double x = (double)d1 / d, y = (double)d2 / d;
		// 若该交点真正在两直线上（其实只需判断在直线1上即可）
		if (_is_d_between(x11, x12, x) && _is_d_between(y11, y12, y)) {
			return _return_cor(x, y, length_p);
		} else {
			return _return_null(length_p);
		}
	} else if (dx1 * y21 - dy1 * x21 == c1) {
		return _int_co(x11, y11, x12, y12, x21, y21, x22, y22,
			       length_p);
	} else {
		return _return_null(length_p);
	}
}