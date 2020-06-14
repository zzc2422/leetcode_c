#include "include_all.h"

static int* _sget_sum(struct TreeNode* root_p, int* p) {
	if (root_p == NULL) {
		return NULL;
	}
	int *sum_p = _sget_sum(root_p->left, p), left_sum;
	if (sum_p == NULL) {
		left_sum = 0;
	} else {
		left_sum = sum_p[-1];
		p = sum_p;
	}
	sum_p = _sget_sum(root_p->right, p);
	int right_sum;
	if (sum_p == NULL) {
		right_sum = 0;
	} else {
		right_sum = sum_p[-1];
		p = sum_p;
	}
	int sum = left_sum + right_sum + root_p->val;
	*p = sum;
	return p + 1;
}

static int _get_node_amount(struct TreeNode* root_p) {
	if (root_p == NULL) {
		return 0;
	}
	int left_amount = _get_node_amount(root_p->left);
	int right_amount = _get_node_amount(root_p->right);
	return left_amount + right_amount + 1;
}

int maxProduct(struct TreeNode* root_p) {
	int node_amount = _get_node_amount(root_p);
	int value_a[node_amount];
	const int* all_sum_p = _sget_sum(root_p, value_a);
	int all_sum = all_sum_p[-1], min_dif = all_sum;
	for (const int* p = value_a; p != value_a + node_amount; p++) {
		int sum = *p;
		int other = all_sum - sum;
		int dif = sum - other;
		if (dif < 0) {
			dif = -dif;
		}
		if (dif < min_dif) {
			min_dif = dif;
		}
	}
	int min = (all_sum - min_dif) >> 1;
	int max = min + min_dif;
	int MOD = 1000000007;
	long long result_without_mod =
		(long long)(min % MOD) * (long long)(max % MOD);
	return result_without_mod % MOD;
}