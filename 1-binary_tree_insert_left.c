#include "binary_trees.h"

/**
* binary_tree_insert_left - inserts a node as the left-child of another node
* @parent: pointer to the node to insert the left-child in
* @value: value to store in the new node
* Return: pointer to the created node or NULL on failure or if parent is NULL
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (!parent || !node)
	{
		free(node);
		return (NULL);
	}
	node->left = NULL;
	node->right = NULL;
	node->n = value;
	node->parent = parent;

	if (!parent->left)
		parent->left = node;

	else
	{
		binary_tree_t *tmp = parent->left;

		parent->left = node;
		tmp->parent = node;
		node->left = tmp;
	}
	return (node);
}
