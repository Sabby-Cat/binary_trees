#include "binary_trees.h"
/**
 * binary_tree_depth - measure  depth of node in tree
 * @tree: node to calculate depth of
 * Return: depth of node or 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);
	while (tree->parent)
	{
		depth++;
		tree = tree->parent;
	}
	return (depth);
}
