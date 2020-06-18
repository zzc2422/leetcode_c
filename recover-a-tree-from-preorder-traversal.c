#include "include_all.h"

typedef struct {
	int value;
	unsigned layer;
} val_lay_t;

static unsigned _is_num(char c) {
	return c >= '0' && c <= '9';
}

static unsigned _get_node_amount(const char str_a[]) {
	const char* cp = str_a;
	unsigned node_amount = 0;
	while (1) {
		char c;
		do {
			c = *cp;
			cp++;
		} while (_is_num(c));
		node_amount++;
		if (c == '\0') {
			return node_amount;
		}
		do {
			c = *cp;
			cp++;
		} while (c == '-');
	}
}

static unsigned _set_val_lay(const char str_a[], val_lay_t val_lay_a[]) {
	val_lay_t* vlp = val_lay_a;
	vlp->layer = 0;
	const char* cp = str_a;
	char c = str_a[0];
	unsigned max_layer = 0;
	while (1) {
		int value = 0;
		while (1) {
			value += c - '0';
			cp++;
			c = *cp;
			if (!_is_num(c)) {
				break;
			}
			value *= 10;
		}
		vlp->value = value;
		if (c == '\0') {
			break;
		}
		vlp++;
		const char* stick_start_p = cp;
		do {
			cp++;
			c = *cp;
		} while (c == '-');
		int layer = cp - stick_start_p;
		vlp->layer = layer;
		if (layer > max_layer) {
			max_layer = layer;
		}
	}
	return max_layer;
}

struct TreeNode* recoverFromPreorder(char str_a[]) {
	unsigned node_amount = _get_node_amount(str_a);
	val_lay_t val_lay_a[node_amount];
	unsigned depth = _set_val_lay(str_a, val_lay_a) + 1;
	struct TreeNode* node_pool_a =
		malloc(sizeof(struct TreeNode[node_amount]));
	struct TreeNode* pool_p = node_pool_a;
	struct TreeNode *stack_pa[depth], **spp = stack_pa;
	struct TreeNode *result_p, **child_pp = &result_p;
	for (const val_lay_t* vlp = val_lay_a; vlp != val_lay_a + node_amount;
	     vlp++) {
		pool_p->val = vlp->value;
		pool_p->right = NULL;
		unsigned layer = vlp->layer;
		struct TreeNode** new_spp = stack_pa + layer;
		if (new_spp != spp) {
			spp = new_spp;
			*child_pp = NULL;
			child_pp = &(spp[-1]->right);
		}
		*spp = *child_pp = pool_p;
		spp++;
		child_pp = &(pool_p->left);
		pool_p++;
	}
	*child_pp = NULL;
	return result_p;
}