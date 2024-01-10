#include "binary_trees.h"
/**
* bst_insert_helper - helps to insert a new value to bst
* @tree: root node of the binary tree
* @value: value to put in the new node
* Return: pointer to new node or NULL on failure
*/
bst_t *bst_insert_helper(bst_t *tree, int value)
{
	bst_t *new_node = NULL;

	if (tree->n > value)
	{
		if (!tree->left)
		{
			new_node = binary_tree_node(tree, value);
			tree->left = new_node;
			return (new_node);
		}
		return (bst_insert_helper(tree->left, value));
	}

	if (tree->n < value)
	{
		if (!tree->right)
		{
			new_node = binary_tree_node(tree, value);
			tree->right = new_node;
			return (new_node);
		}
		return (bst_insert_helper(tree->right, value));
	}
	return (NULL);

}

/**
* bst_insert - inserts a value in a Binary Search Tree
* @tree: double pointer to the root node of the BST to insert the value
* @value: value to store in the node to be inserted
* Return: pointer to the created node, or NULL on failure
*/
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node = NULL;

	if (!(*tree) || !tree)
	{
		new_node = binary_tree_node(NULL, value);
		*tree = new_node;

		return (new_node);

	}
	return (bst_insert_helper(*tree, value));
}
