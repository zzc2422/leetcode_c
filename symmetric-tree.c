#include "include_all.h"

static bool _is_sym(struct TreeNode* tree1_p, struct TreeNode* tree2_p) {
	if (tree1_p == NULL || tree2_p == NULL) {
		return tree1_p == tree2_p;
	} else if (tree1_p->val != tree2_p->val) {
		return false;
	}
	return _is_sym(tree1_p->left, tree2_p->right) &&
	       _is_sym(tree2_p->left, tree1_p->right);
}

bool isSymmetric(struct TreeNode* root_p) {
	return _is_sym(root_p, root_p);
}