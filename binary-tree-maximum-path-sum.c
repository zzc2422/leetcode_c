#include "include_all.h"

typedef struct {
	unsigned node_amount, height;
} tree_info_t;

static tree_info_t _get_tree_info(const struct TreeNode* root_p) {
	if (root_p == NULL) {
		tree_info_t tree_info = {.node_amount = 0, .height = 0};
		return tree_info;
	}
	tree_info_t left_info = _get_tree_info(root_p->left);
	tree_info_t right_info = _get_tree_info(root_p->right);
	unsigned left_node_amount = left_info.node_amount;
	unsigned right_node_amount = right_info.node_amount;
	unsigned left_height = left_info.height;
	unsigned right_height = right_info.height;
	unsigned node_amount = left_node_amount + right_node_amount + 1;
	unsigned height =
		(left_height >= right_height ? left_height : right_height) + 1;
	tree_info_t tree_info = {.node_amount = node_amount, .height = height};
	return tree_info;
}

int maxPathSum(struct TreeNode* root_p) {
	tree_info_t tree_info = _get_tree_info(root_p);
	unsigned node_amount = tree_info.node_amount;
	unsigned height = tree_info.height;
	struct TreeNode *pool_pa[node_amount], **pool_pp = pool_pa;
	struct TreeNode *stack_pa[height], **spp = stack_pa;
	struct TreeNode* node_p = root_p;
	while (1) {
		if (node_p == NULL) {
			while (node_p == NULL) {
				spp--;
				struct TreeNode* parent_p = *spp;
				node_p = parent_p->right;
			}
			spp++;
		}
	}
}