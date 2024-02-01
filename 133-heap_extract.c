#include "binary_trees.h"
void recurse_extract(heap_t *tree);
heap_t *max(heap_t *tree);
/**
 * heap_extract - Extract root node of Max Binary Heap
 * @root: double pointer to root node of heap
 * Return: value stored in root node
 */
int heap_extract(heap_t **root)
{
	int val;

	if (!*root)
		return (0);
	val = (*root)->n;
	if (!(*root)->left)
	{
		val = (*root)->n;
		free(*root);
		*root = NULL;
		return (val);
	}
	recurse_extract(*root);
	return (val);
}

/**
 * recurse_extract - Recursively extract max from tree
 * @tree: pointer to root of tree
 */
void recurse_extract(heap_t *tree)
{
	heap_t *s_max, *r_max = NULL;

	if (!tree->left)
		return;
	s_max = max((tree)->left);
	if (tree->right)
		r_max = max(tree->right);
	if (r_max && r_max->n > s_max->n)
		s_max = r_max;
	tree->n = s_max->n;
	if (!s_max->left)
	{
		if (s_max->parent && s_max->parent->left == s_max)
			s_max->parent->left = NULL;
		if (s_max->parent && s_max->parent->right == s_max)
			s_max->parent->right = NULL;
		free(s_max);
	}
	else
		recurse_extract(s_max);
}

/**
 * max - Find maximum node in tree
 * @tree: pointer to root of tree
 * Return: node with maximum value
 */
heap_t *max(heap_t *tree)
{
	heap_t *max_cur, *l_max, *r_max;

	if (!tree->left)
		return (tree);
	l_max = max(tree->left);
	if (l_max->n > tree->n)
		max_cur = l_max;
	else
		max_cur = tree;
	if (tree->right)
	{
		r_max = max(tree->right);
		if (r_max->n > max_cur->n)
			max_cur = r_max;
		else
			max_cur = tree;
	}
	return (max_cur);
}
