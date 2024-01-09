#include "binary_trees.h"

/**
 * binary_tree_inorder - Go throught a binary tree in traversal
 * in-order
 * @tree: Pointer to the root of the tree
 * @func: Function to call for each node
 * If no tree or no func return
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
