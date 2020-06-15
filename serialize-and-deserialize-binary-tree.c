
#include "include_all.h"

static unsigned _get_node_amount(struct TreeNode* root_p) {
	if (root_p == NULL) {
		return 0;
	}
	return _get_node_amount(root_p->left) +
	       _get_node_amount(root_p->right) + 1;
}

static struct TreeNode* _make_tree(struct TreeNode* root_p,
				   struct TreeNode node_pool_a[]) {
	if (root_p == NULL) {
		return node_pool_a;
	}
	node_pool_a[0] = *root_p;
	node_pool_a = _make_tree(root_p->left, node_pool_a + 1);
	node_pool_a = _make_tree(root_p->right, node_pool_a);
	return node_pool_a;
}

char* serialize(struct TreeNode* root_p) {
	if (root_p == NULL) {
		return NULL;
	}
	int node_amount = _get_node_amount(root_p);
	struct TreeNode* node_pool_a =
		malloc(sizeof(struct TreeNode[node_amount]));
	_make_tree(root_p, node_pool_a);
	return (char*)node_pool_a;
}

struct TreeNode* deserialize(char data_a[]) {
	return (struct TreeNode*)data_a;
}