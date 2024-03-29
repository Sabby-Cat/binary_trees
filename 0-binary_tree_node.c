#include "binary_trees.h"
/**
 * binary_tree_node - create binary tree node
 * @parent: pointer to parent node of new node
 * @value: value for new node
 * Return: Pointer to new node or null
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);
	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
