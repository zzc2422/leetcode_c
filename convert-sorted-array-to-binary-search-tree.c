#include "include_all.h"

struct TreeNode* sortedArrayToBST(int a[], int length) {
	if (length == 0) {
		return NULL;
	}
	int middle_index = length >> 1;
	const struct TreeNode* left_p = sortedArrayToBST(a, middle_index);
	const struct TreeNode* right_p = sortedArrayToBST(
		a + middle_index + 1, length - middle_index - 1);
	struct TreeNode* root_p = malloc(sizeof(struct TreeNode));
	root_p->val = a[middle_index];
	root_p->left = left_p;
	root_p->right = right_p;
	return root_p;
}