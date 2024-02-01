#include "binary_trees.h"
/**
 * binary_tree_height - measure  height of binary tree
 * @tree: tree to measure height of
 * Return: height of tree or 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h_l = 0;
	size_t h_r = 0;

	if (!tree)
		return (0);
	h_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	h_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (h_l > h_r ? h_l : h_r);
}
