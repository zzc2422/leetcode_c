#include "include_all.h"

static int _get_depth(const struct TreeNode* root_p) {
	if (root_p == NULL) {
		return 0;
	}
	int left_depth = _get_depth(root_p->left);
	int right_depth = _get_depth(root_p->right);
	return (left_depth > right_depth ? left_depth : right_depth) + 1;
}

static int** _value_a(const struct TreeNode* const* layer_ppa[], int lna_a[],
		      int depth) {
	for (int layer = 0; layer != depth; layer++) {
		int lna = lna_a[layer];
		const struct TreeNode* const* ln_pa = layer_ppa[layer];
		int* value_a = (int*)ln_pa;
		for (int i = 0; i != lna; i++) {
			value_a[i] = ln_pa[i]->val;
		}
		// 理论上只需realloc而不需将结果赋给左边的，因为是减小申请空间，
		// 但不知道为什么去掉左边会通不过。很费解。
		layer_ppa[layer] = realloc(value_a, sizeof(int[lna]));
	}
	return (int**)layer_ppa;
}

int** levelOrder(const struct TreeNode* root_p, int* depth_p, int** lna_pp) {
	if (root_p == NULL) {
		*depth_p = 0;
		return malloc(0);
	}
	int depth = _get_depth(root_p);
	// lna为layer node amount，每层结点个数。
	int* lna_a = malloc(sizeof(int[depth]));
	lna_a[0] = 1;
	int next_layer = 1, lna = 1;
	// ln为layer node，每层的结点。ln_ppa[i][j]为第i层第j个结点的地址。
	const struct TreeNode* const** layer_ppa =
		malloc(sizeof(struct TreeNode * *[depth]));
	// 第0层只有1个结点，即根结点。
	const struct TreeNode** ln_pa = malloc(sizeof(struct TreeNode*));
	ln_pa[0] = root_p;
	layer_ppa[0] = ln_pa;
	while (next_layer != depth) {
		int next_lna = 0;
		for (const struct TreeNode** node_pp = ln_pa;
		     node_pp != ln_pa + lna; node_pp++) {
			const struct TreeNode* node_p = *node_pp;
			if (node_p->left != NULL) {
				next_lna++;
			}
			if (node_p->right != NULL) {
				next_lna++;
			}
		}
		const struct TreeNode** next_ln_pa =
			malloc(sizeof(struct TreeNode* [next_lna]));
		lna_a[next_layer] = next_lna;
		layer_ppa[next_layer] = next_ln_pa;
		const struct TreeNode** nln_pp = next_ln_pa;
		for (const struct TreeNode** node_pp = ln_pa;
		     node_pp != ln_pa + lna; node_pp++) {
			const struct TreeNode* node_p = *node_pp;
			const struct TreeNode* left_p = node_p->left;
			if (left_p != NULL) {
				*nln_pp = left_p;
				nln_pp++;
			}
			const struct TreeNode* right_p = node_p->right;
			if (right_p != NULL) {
				*nln_pp = right_p;
				nln_pp++;
			}
		}
		lna = next_lna;
		ln_pa = next_ln_pa;
		next_layer++;
	}
	*depth_p = depth;
	*lna_pp = lna_a;
	return _value_a(layer_ppa, lna_a, depth);
}
/*













































*/