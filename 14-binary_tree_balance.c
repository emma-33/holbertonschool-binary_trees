#include "binary_trees.h"
/**
 * binary_tree_balance - Measure the balance factor of
 * a tree
 * @tree: Pointer to the root of the tree
 * Return: Measured balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int heightL = -1;
	int heightR = -1;

	if (tree == NULL)
		return (0);

	if (tree->left)
		heightL = (int)binary_tree_height(tree->left);
	if (tree->right)
		heightR = (int)binary_tree_height(tree->right);

	return (heightL - heightR);
}
