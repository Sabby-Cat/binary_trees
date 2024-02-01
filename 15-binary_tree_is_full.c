#include "binary_trees.h"
/**
 * binary_tree_is_full - check if tree is full
 * @tree: pointer to root node of tree
 * Return: 1 if tree is full or 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->right && !tree->left)
		return (1);
	if (tree->right && tree->left)
		return (binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right));
	return (0);
}
