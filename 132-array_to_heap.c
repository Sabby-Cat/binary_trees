#include "binary_trees.h"
/**
 * array_to_heap - Build Max Binary Heap tree from array
 * @array: pointer to first element
 * @size: number of element in  array
 * Return: pointer to root node of created or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int idx;
	heap_t *root = NULL;

	for (idx = 0; idx < size; idx++)
		heap_insert(&root, array[idx]);
	return (root);
}
