#include "binary_trees.h"
/**
* array_to_bst - builds a binary search tree from an array
* @array: pointer to the first element of the array to be converted
* @size: number of elements in the arrays
* Return: pointer to the root node of the created bst or NULL on failure
*/
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i = 0;

	bst_t *root = NULL;

	while (i < size)
	{
		bst_insert(&root, array[i]);
		i++;
	}
	return (root);
}
