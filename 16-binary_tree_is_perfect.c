#include "binary_trees.h"
int is_perfect_recursive(const binary_tree_t *tree,
		size_t depth, size_t level);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
size_t depth(const binary_tree_t *tree);
unsigned char is_leaf(const binary_tree_t *tree);
/**
 * binary_tree_is_perfect - Check if tree is perfect
 * @tree: pointer to root of tree to check
 * Return: 0 if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}

/**
 * depth - Return depth of tree
 * @tree: pointer to tree to measure depth of
 * Return: depth of tree
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf - Return leaf of tree
 * @tree: pointer to root of tree to find leaf in
 * Return: pointer to first leaf
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_recursive - Check if tree is perfect recursively
 * @tree: pointer to root of tree to check
 * @depth: depth of one leaf of tree
 * @level: Level of current tree
 * Return: If tree is perfect 1, else 0
 */
int is_perfect_recursive(const binary_tree_t *tree,
		size_t depth, size_t level)
{
	if (is_leaf(tree))
		return (level == depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, depth, level + 1) &&
		is_perfect_recursive(tree->right, depth, level + 1));
}

/**
 * is_leaf - Check if node is leaf of tree
 * @tree: pointer to node to check
 * Return: If node is leaf 1, else 0
 */
unsigned char is_leaf(const binary_tree_t *tree)
{
	return ((tree->left == NULL && tree->right == NULL) ? 1 : 0);
}
