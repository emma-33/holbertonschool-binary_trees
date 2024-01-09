#include "binary_trees.h"

/**
 * binary_tree_postorder - Go throught a binary tree in traversal
 * post-order
 * @tree: Pointer to the root of the tree
 * @func: Function to call for each node
 * If no tree or no func return
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
