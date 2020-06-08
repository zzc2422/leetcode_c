#include "include_all.h"

static bool _has_path(struct TreeNode* root_p, int sum) {
	int rest_value = sum - root_p->val;
	if (root_p->left == NULL && root_p->right == NULL) {
		return !rest_value;
	}
	bool left_has_path =
		root_p->left != NULL && _has_path(root_p->left, rest_value);
	if (left_has_path) {
		return true;
	} else if (root_p->right == NULL) {
		return false;
	} else {
		return _has_path(root_p->right, rest_value);
	}
}

bool hasPathSum(struct TreeNode* root_p, int sum) {
	if (root_p == NULL) {
		return false;
	}
	return _has_path(root_p, sum);
}