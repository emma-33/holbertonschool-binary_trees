#include "binary_trees.h"

/**
 * binary_tree_preorder - Go throught a binary tree in traversal
 * pre-order
 * @tree: Pointer to the root of the tree
 * @func: Function to call for each node
 * If no tree or no func return
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
