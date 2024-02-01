#include "binary_trees.h"
int check_parent(const binary_tree_t *tree);
int complete_bt(const binary_tree_t *tree);
int complete_tree(const binary_tree_t *tree, int i, int cnod);
size_t size_bt(const binary_tree_t *tree);
/**
 * binary_tree_is_heap - Check if binary tree is valid Max Binary Heap
 * @tree: pointer to root node of tree
 * Return: 1 if tree is a valid or 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!complete_bt(tree))
		return (0);
	return (check_parent(tree->left) && check_parent(tree->right));
}

/**
 * check_parent - Check if parent has greater value than its child
 * @tree: pointer to node
 * Return: 1 if parent has greater value or 0
 */
int check_parent(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);
	if (tree->n > tree->parent->n)
		return (0);
	return (check_parent(tree->left) && check_parent(tree->right));
}

/**
 * complete_bt - Call to complete_tree func
 * @tree: Tree root
 * Return: 1 if tree is complete or 0
 */
int complete_bt(const binary_tree_t *tree)
{
	size_t cnod;

	if (tree == NULL)
		return (0);
	cnod = size_bt(tree);
	return (complete_tree(tree, 0, cnod));
}

/**
 * complete_tree - Checks if tree is complete
 * @tree: Pointer to tree root
 * @i: Node index
 * @cnod: Nr of nodes
 * Return: 1 if tree is complete or 0
 */
int complete_tree(const binary_tree_t *tree, int i, int cnod)
{
	if (tree == NULL)
		return (1);
	if (i >= cnod)
		return (0);
	return (complete_tree(tree->left, (2 * i) + 1, cnod) &&
		complete_tree(tree->right, (2 * i) + 2, cnod));
}

/**
 * size_bt - Measures size of binary tree
 * @tree: Tree root
 * Return: Size of tree or 0
 */
size_t size_bt(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (size_bt(tree->left) + size_bt(tree->right) + 1);
}
