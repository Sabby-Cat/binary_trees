#include "binary_trees.h"
/**
 * binary_tree_rotate_right - rotates binary tree right
 * @tree: pointer to root node of tree
 * Return: Pointer to new root node of rotated tree or null
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tmp = NULL, *pre;

	if (!tree || !tree->left)
		return (NULL);
	tmp = tree;
	pre = tree->pre;
	tree = tree->left;
	tree->pre = NULL;
	if (tree->right)
	{
		tmp->left = tree->right;
		tree->right->pre = tmp;
	}
	else
		tmp->left = NULL;
	tmp->pre = tree;
	tree->right = tmp;
	if (pre)
		pre->left = tree;
	tree->pre = pre;
	return (tree);
}
