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
