#include "binary_trees.h"
int bt_check(const binary_tree_t *tree, size_t index, size_t size);
size_t binary_tree_size(const binary_tree_t *tree);
/**
 * binary_tree_is_complete - check if binary tree is complete
 * @tree: pointer to root node of tree
 * Return: 1 if tree is complete or 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);
	size = binary_tree_size(tree);
	return (bt_check(tree, 0, size));
}

/**
 * bt_check - check if binary tree is complete
 * @tree: pointer to root node of tree
 * @index: index to check
 * @size: nr of nodes in tree
 * Return: 1 if tree is complete or 0
 */
int bt_check(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);
	if (index >= size)
		return (0);
	return (bt_check(tree->left, 2 * index + 1, size) &&
		bt_check(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - measures size of binary tree
 * @tree: tree to get size of
 * Return: size of tree or 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}
