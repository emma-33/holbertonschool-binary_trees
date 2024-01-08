#include "binary_trees.h"
/**
* binary_tree_height - measures the height of a binary tree
* @tree: pointer to the root node of the tree to measure the height
* Return: height of a binary tree or 0
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree || (!tree->left && !tree->right))
		return (0);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	if (left >= right)
		return (left + 1);
	else
		return (right + 1);
}

/**
* binary_tree_is_perfect - checks if a binary tree is perfect
* @tree: pointer to the root node of the tree to check
* Return: 1 if perfect, else 0
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (!tree)
		return (0);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	if (left == right)
	{
		if (!tree->left && !tree->right)
			return (1);
		if (tree->left && tree->right && binary_tree_is_perfect(tree->left)
		&& binary_tree_is_perfect(tree->right))
			return (1);
	}
	return (0);
}
