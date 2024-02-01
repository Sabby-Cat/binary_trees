#include "binary_trees.h"
/**
 * bst_search - Search for value in Binary Search Tree
 * @tree: pointer to root node of the BST
 * @value: value to search in tree
 * Return: pointer to node containing value equal to value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));

		return (bst_search(tree->right, value));
	}
	return (NULL);
}
