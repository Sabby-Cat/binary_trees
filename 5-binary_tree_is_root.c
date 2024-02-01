#include "binary_trees.h"
/**
 * binary_tree_is_root - check if node is root
 * @node: node to check
 * Return: 1 if node is root else 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	return ((!node || node->parent) ? 0 : 1);
}
