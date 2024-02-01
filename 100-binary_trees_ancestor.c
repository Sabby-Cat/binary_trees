#include "binary_trees.h"
/**
 * binary_trees_ancestor - Find lowest common ancestor of two nodes
 * @first: pointer to first node
 * @second: pointer to second node
 * Return: pointer to lowest common ancestor of given nodes or null
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *lp, *rp;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);
	lp = first->parent, rp = second->parent;
	if (first == rp || !lp || (!lp->parent && rp))
		return (binary_trees_ancestor(first, rp));
	else if (lp == second || !rp || (!rp->parent && lp))
		return (binary_trees_ancestor(lp, second));
	return (binary_trees_ancestor(lp, rp));
}
