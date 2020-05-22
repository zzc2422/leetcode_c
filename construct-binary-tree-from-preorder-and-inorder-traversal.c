#include "include_all.h"

struct TreeNode* _build_tree(const int preorder_a[], const int inorder_a[],
			     int node_amount) {
	if (node_amount == 0) {
		return NULL;
	}
	int root_value = preorder_a[0], inorder_root_index;
	struct TreeNode* root_p = malloc(sizeof(struct TreeNode));
	root_p->val = root_value;
	for (int i = 0;; i++) {
		int value = inorder_a[i];
		if (value == root_value) {
			inorder_root_index = i;
			break;
		}
	}
	struct TreeNode* left_p =
		_build_tree(preorder_a + 1, inorder_a, inorder_root_index);
	struct TreeNode* right_p =
		_build_tree(preorder_a + inorder_root_index + 1,
			    inorder_a + inorder_root_index + 1,
			    node_amount - inorder_root_index - 1);
	root_p->left = left_p;
	root_p->right = right_p;
	return root_p;
}

struct TreeNode* buildTree(int preorder_a[], int length, int inorder_a[],
			   int no_use) {
	return _build_tree(preorder_a, inorder_a, length);
}