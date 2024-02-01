#include "binary_trees.h"
/**
 * binary_tree_nodes - Count nodes with at least 1 child in tree
 * @tree: pointer to root node of tree to count nodes
 * Return: 0 if tree NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nr = 0;

	if (tree)
	{
		nr += (tree->left || tree->right) ? 1 : 0;
		nr += binary_tree_nodes(tree->left);
		nr += binary_tree_nodes(tree->right);
	}
	return (nr);
}
