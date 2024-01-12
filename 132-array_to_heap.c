#include "binary_trees.h"
/**
* array_to_heap - builds a max binary heap tree from an array
* @array: pointer to the first element of the array to be converted
* @size: number of elements in the array
* Return: pointer to the root node of the created binary heap or
* NULL on failure
*/
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *tree = NULL;
	size_t i = 0;

	while (i < size)
	{
		heap_insert(&tree, array[i]);
		i++;
	}
	return (tree);
}
