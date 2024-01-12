#include "binary_trees.h"
#include <limits.h>

/**
* is_bst_helper - help function to check if tree is a BST
* @tree: pointer to the root node of the tree to check
* @min: minimum value
* @max: maximum value
* Return: 1 if tree is a BST, otherwise 0
*/
int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst_helper(tree->left, min, tree->n) &&
			is_bst_helper(tree->right, tree->n, max));
}
/**
* binary_tree_is_bst - checks if a binary tree is a valid binary search tree
* @tree: pointer to the root node of the tree to check
* Return: 1 if tree is valid, otherwise 0 and if tree is NULL
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
