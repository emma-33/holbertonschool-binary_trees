#include "binary_trees.h"
/**
* binary_tree_size - measures the size of a binary tree
* @tree: pointer to the root node of the tree to measure the size
* Return: size of the tree or 0
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);
	left = binary_tree_size(tree->left);
	right = binary_tree_size(tree->right);

	return (left + 1 + right);
}
/**
* is_complete - helper func to check if the tree is complete
* @tree: pointer to the root node of the tree to check
* @index: index
* @num_nodes: number of nodes
* Return: 1 if complete, 0 otherwise or if tree is NULL
*/
int is_complete(const binary_tree_t *tree, int index, int num_nodes)
{
	if (!tree)
		return (1);
	if (index >= num_nodes)
		return (0);
	return (is_complete(tree->left, 2 * index + 1, num_nodes)
			&& is_complete(tree->right, 2 * index + 2, num_nodes));
}

/**
* binary_tree_is_complete - checks if a binary tree is complete
* @tree: pointer to the root node of the tree to check
* Return: 1 if complete, 0 otherwise or if tree is NULL
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int index = 0;

	size_t num_nodes = binary_tree_size(tree);

	if (!tree)
		return (0);

	return (is_complete(tree, index, num_nodes));
}

