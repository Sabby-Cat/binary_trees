#include "binary_trees.h"
/**
 * binary_tree_rotate_left - rotates binary tree left
 * @tree: pointer to root node of tree
 * Return: Pointer to new root node of rotated tree or null
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp = NULL, *pre;

	if (!tree || !tree->right)
		return (NULL);
	tmp = tree;
	pre = tree->pre;
	tree = tree->right;
	tree->pre = NULL;
	if (tree->left)
	{
		tmp->right = tree->left;
		tree->left->pre = tmp;
	}
	else
		tmp->right = NULL;
	tmp->pre = tree;
	tree->left = tmp;
	if (pre)
		pre->right = tree;
	tree->pre = pre;
	return (tree);
}
