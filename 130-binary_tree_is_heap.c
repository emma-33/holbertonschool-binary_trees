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
/**
* is_heap - helps check if a binary tree is a valid max binary heap
* @tree: pointer to the root node to check
* Return: 1 if tree is a valid max binary heap, 0 otherwise or if tree is NULL
*/
int is_heap(const binary_tree_t *tree)
{
	if (!tree->left && !tree->right)
		return (1);

	if (!tree->right)
		return (tree->n >= tree->left->n);

	else
	{
		if (tree->n >= tree->left->n && tree->n >= tree->right->n)
			return (is_heap(tree->left) && is_heap(tree->right));
		else
			return (0);
	}
}

/**
* binary_tree_is_heap - checks if a binary tree is a valid max binary heap
* @tree: pointer to the root node to check
* Return: 1 if tree is a valid max binary heap, 0 otherwise or if tree is NULL
*/
int binary_tree_is_heap(const binary_tree_t *tree)
{

	if (!tree)
		return (0);
	if (binary_tree_is_complete(tree) && is_heap(tree))
		return (1);
	return (0);
}
