#include "include_all.h"

static int _get_layer_amount(const struct TreeNode* tree_p) {
	if (tree_p == NULL) {
		return 0;
	}
	const struct TreeNode *left_p = tree_p->left, *right_p = tree_p->right;
	int left_layer = _get_layer_amount(left_p);
	int right_layer = _get_layer_amount(right_p);
	return (left_layer > right_layer ? left_layer : right_layer) + 1;
}

typedef struct {
	int* right_a;
	const struct TreeNode** node_pa;
} layout_t;

static layout_t _malloc(int depth) {
	size_t p_size_m1 = sizeof(struct TreeNode*) - 1;
	size_t ret_align_size = (sizeof(int[depth]) + p_size_m1) & (~p_size_m1);
	size_t total_size = ret_align_size + sizeof(struct TreeNode* [depth]);
	char* space_a = malloc(total_size);
	layout_t layout = {
		.right_a = (int*)space_a,
		.node_pa = (const struct TreeNode**)(space_a + ret_align_size)};
	return layout;
}

static int* _write_right(const struct TreeNode* tree_p, int depth) {
	layout_t layout = _malloc(depth);
	int* right_a = layout.right_a;
	const struct TreeNode** node_pa = layout.node_pa;
	const struct TreeNode* node_p = tree_p;
	int layer_th = 0, value_amount = 0;
	while (1) {
		while (node_p != NULL) {
			if (layer_th == value_amount) {
				right_a[value_amount] = node_p->val;
				value_amount++;
			}
			node_pa[layer_th] = node_p;
			node_p = node_p->right;
			layer_th++;
		}
		if (layer_th == depth) {
			return right_a;
		}
		while (1) {
			node_p = node_pa[layer_th - 1];
			if (node_p != NULL) {
				break;
			}
			layer_th--;
		}
		node_pa[layer_th - 1] = NULL;
		node_p = node_p->left;
	}
}

int* rightSideView(struct TreeNode* tree_p, int* depth_p) {
	int depth = _get_layer_amount(tree_p);
	*depth_p = depth;
	return _write_right(tree_p, depth);
}