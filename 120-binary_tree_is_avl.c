#include "binary_trees.h"
int avl_check(const binary_tree_t *tree, int low, int high);
size_t height(const binary_tree_t *tree);
/**
 * binary_tree_is_avl - Check if binary tree is valid AVL Tree
 * @tree: pointer to root node of tree
 * Return: 1 if valid AVL Tree, else 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (avl_check(tree, INT_MIN, INT_MAX));
}

/**
 * avl_check - Check if binary tree is valid AVL tree
 * @tree: pointer to root node of tree to check
 * @low: value of smallest node visited
 * @high: value of largest node visited
 * Return: 1 if valid else 0
 */
int avl_check(const binary_tree_t *tree, int low, int high)
{
	size_t lh, rh, diff;

	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);
		lh = height(tree->left);
		rh = height(tree->right);
		diff = lh > rh ? lh - rh : rh - lh;
		if (diff > 1)
			return (0);
		return (avl_check(tree->left, low, tree->n - 1) &&
			avl_check(tree->right, tree->n + 1, high));
	}
	return (1);
}

/**
 * height - Measure height of binary tree
 * @tree: pointer to root node of tree to measure height of
 * Return: height or 0
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + height(tree->left) : 1;
		r = tree->right ? 1 + height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}
