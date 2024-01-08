#include "binary_trees.h"

/**
* binary_tree_insert_right - inserts a node as the right-child of another node
* @parent: pointer to the node to insert the right-child in
* @value: value to store in the new node
* Return: pointer to the created node or NULL on failure or if parent is NULL
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (node == NULL)
		return (NULL);

	if (parent == NULL)
	{
		free(node);
		return (NULL);
	}
	node->right = NULL;
	node->right = NULL;
	node->n = value;
	node->parent = parent;

	if (parent->right == NULL)
		parent->right = node;

	else
	{
		binary_tree_t *tmp = parent->right;

		parent->right = node;
		tmp->parent = node;
		node->right = tmp;
	}
	return (node);
}
