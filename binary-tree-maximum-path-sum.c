#include "include_all.h"

static unsigned _get_node_amount(const struct TreeNode* root_p) {
	if (root_p == NULL) {
		return 0;
	}
	unsigned left_node_amount = _get_node_amount(root_p->left);
	unsigned right_node_amount = _get_node_amount(root_p->right);
	return left_node_amount + right_node_amount + 1;
}

static struct TreeNode* _make_tree(const struct TreeNode* root_p,
				   struct TreeNode pool_a[]) {
	struct TreeNode* left_p = root_p->left;
	if (left_p != NULL) {
		left_p = _make_tree(left_p, pool_a);
		pool_a = left_p + 1;
	}
	struct TreeNode* right_p = root_p->right;
	if (right_p != NULL) {
		right_p = _make_tree(right_p, pool_a);
		pool_a = right_p + 1;
	}
	struct TreeNode* node_p = pool_a;
	node_p->val = root_p->val;
	node_p->left = left_p;
	node_p->right = right_p;
	return node_p;
}

int maxPathSum(struct TreeNode* root_p) {
	unsigned node_amount = _get_node_amount(root_p);
	struct TreeNode pool_a[node_amount];
	_make_tree(root_p, pool_a);
	int max_sum_a[node_amount], max_double_sum = root_p->val, i = 0;
	while (1) {
		const struct TreeNode* node_p = pool_a + i;
		int value = node_p->val, double_sum = value;
		const struct TreeNode* left_p = node_p->left;
		int left_sum;
		if (left_p == NULL) {
			left_sum = 0;
		} else {
			left_sum = max_sum_a[left_p - pool_a];
			if (left_sum > 0) {
				double_sum += left_sum;
			}
		}
		const struct TreeNode* right_p = node_p->right;
		int right_sum;
		if (right_p == NULL) {
			right_sum = 0;
		} else {
			right_sum = max_sum_a[right_p - pool_a];
			if (right_sum > 0) {
				double_sum += right_sum;
			}
		}
		if (double_sum > max_double_sum) {
			max_double_sum = double_sum;
		}
		i++;
		if (i == node_amount) {
			break;
		}
		int max_sum = (left_sum >= right_sum ? left_sum : right_sum);
		if (max_sum < 0) {
			max_sum = 0;
		}
		max_sum += value;
		max_sum_a[i - 1] = max_sum;
	}
	return max_double_sum;
}