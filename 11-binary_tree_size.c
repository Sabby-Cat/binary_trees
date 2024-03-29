#include "binary_trees.h"
/**
 * binary_tree_size - measure size of tree
 * @tree: tree to measure size of
 * Return: size of tree or 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
