#include "binary_trees.h"
void bt_check(const binary_tree_t *tree, void (*func)(int), size_t level);
size_t binary_tree_height(const binary_tree_t *tree);
/**
 * binary_tree_levelorder - traverse binary tree using level-order traverse
 * @tree: tree to traverse
 * @func: pointer to func to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t level, maxlevel;

	if (!tree || !func)
		return;
	maxlevel = binary_tree_height(tree) + 1;
	for (level = 1; level <= maxlevel; level++)
		bt_check(tree, func, level);
}

/**
 * bt_check - goes through binary tree using post-order traverse
 * @tree: tree to traverse
 * @func: pointer to func to call for each node
 * @level: level of tree to call func upon
 */
void bt_check(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (level == 1)
		func(tree->n);
	else
	{
		bt_check(tree->left, func, level - 1);
		bt_check(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_height - measures height of binary tree
 * @tree: tree to measure height of
 * Return: height of tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0;
	size_t r = 0;

	if (!tree)
		return (0);
	l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (l > r ? l : r);
}
