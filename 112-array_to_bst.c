#include "binary_trees.h"
/**
 * array_to_bst - builds Binary Search Tree from array
 * @array: pointer to first ele of array
 * @size: nr of ele in array
 * Return: pointer to root node of created BST else null
 */
bst_t *array_to_bst(int *array, size_t size)
{
	unsigned int i;
	bst_t *ret = NULL;

	for (i = 0; i < size; i++)
		bst_insert(&ret, array[i]);
	return (ret);
}
