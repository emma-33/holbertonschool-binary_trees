#include "binary_trees.h"

/**
* search_ancestor - checks the lowest common ancestor of two nodes
* @root: root node to check
* @first: first node
* @second: second node
* Return: pointer to lowest common ancestor or NULL
*/
binary_tree_t *search_ancestor(binary_tree_t *root, const binary_tree_t *first,
								const binary_tree_t *second)
{
	binary_tree_t *left, *right;

	if (!root)
		return (NULL);
	if (root == first || root == second)
		return (root);
	left = search_ancestor(root->left, first, second);
	right = search_ancestor(root->right, first, second);

	if (left && right)
		return (root);

	if (right)
		return (right);
	else
		return (left);
}
/**
* binary_trees_ancestor - finds the lowest common ancestor of two nodes
* @first: pointer to the first node
* @second: pointer to the second node
* Return:  pointer to the lowest common ancestor node of the two given nodes
* or NULL
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									const binary_tree_t *second)
{
	binary_tree_t *root = (binary_tree_t *)first;
	binary_tree_t *root2 = (binary_tree_t *)second;

	if (!first || !second)
		return (NULL);

	while (root->parent)
		root = root->parent;

	while (root2->parent)
		root2 = root2->parent;
	if (root != root2)
		return (NULL);

	return (search_ancestor(root, first, second));
}
