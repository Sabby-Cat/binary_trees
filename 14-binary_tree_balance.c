#include "binary_trees.h"
size_t binary_tree_height(const binary_tree_t *tree);
/**
 * binary_tree_balance - Measures balance factor of tree
 * @tree: pointer to root node of tree to measure balance factor
 * Return: 0 if tree NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - Measure height of tree
 * @tree: pointer to root node of tree to measure height
 * Return: 0 if tree NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}
