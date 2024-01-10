#include "binary_trees.h"

/**
 * binary_tree_uncle - Find the uncle of a node
 * @node: Node to check
 * Return: Uncle or NULL if uncle or node is NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	else
		return (node->parent->parent->left);
}
