#include "binary_trees.h"
/**
 * heap_to_sorted_array - Convert Binary Max Heap to sorted array-integer
 * @heap: pointer to root node of heap
 * @size: address to store size of array
 * Return: Sorted in desc ord
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *arr;
	int extr, i = 0;
	size_t size_h;

	if (!heap)
		return (NULL);
	size_h = binary_tree_size(heap);
	*size = size_h;
	arr = malloc(size_h * sizeof(int));
	if (!arr)
		return (NULL);
	while (heap)
	{
		extr = heap_extract(&heap);
		arr[i] = extr;
		i++;
	}
	return (arr);
}
