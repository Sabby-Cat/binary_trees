#include "binary_trees.h"
int bst_check(const binary_tree_t *tree, int min, int max);
/**
 * binary_tree_is_bst - check if binary tree is valid Binary Search Tree
 * @tree: pointer to root node of tree
 * Return: 1 if valid bst tree  else 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (bst_check(tree, INT_MIN, INT_MAX));
}

/**
 * bst_check - checks if binary tree is valid Binary Search Tree
 * @tree: pointer to root node of tree
 * @min: Lower bound of nodes
 * @max: Upper bound of nodes
 * Return: 1 if valid bst tree else 0
 */
int bst_check(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (bst_check(tree->left, min, tree->n - 1) &&
		bst_check(tree->right, tree->n + 1, max));
}
