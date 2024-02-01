#include "binary_trees.h"
avl_t *sort_l(avl_t *parent, int *array, int first, int last);
/**
 * sorted_array_to_avl - Build an AVL tree from array
 * @array: pointer to first element of array
 * @size: nr of ele in array
 * Return: pointer to root node of created AVL tree or NULL
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (sort_l(NULL, array, 0, ((int)(size)) - 1));
}

/**
 * sort_l - Create tree using half element of array
 * @parent: Parent of node to create
 * @array: Sorted array
 * @first: Position where array starts
 * @last: Position where array ends
 * Return: Tree created
 */
avl_t *sort_l(avl_t *parent, int *array, int first, int last)
{
	avl_t *root;
	binary_tree_t *sto;
	int midl = 0;

	if (first <= last)
	{
		midl = (first + last) / 2;
		sto = binary_tree_node((binary_tree_t *)parent, array[midl]);
		if (sto == NULL)
			return (NULL);
		root = (avl_t *)sto;
		root->left = sort_l(root, array, first, midl - 1);
		root->right = sort_l(root, array, midl + 1, last);
		return (root);
	}
	return (NULL);
}
