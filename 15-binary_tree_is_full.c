#include "binary_trees.h"
/**
* binary_tree_is_full - checks if the binary tree is full
* @tree: pointer to the root of the tree to check
* Return: 1 if full, else 0
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->left && tree->right)
	{
		left = binary_tree_is_full(tree->left);
		right = binary_tree_is_full(tree->right);
		return (left && right);
	}
	return (0);
}
