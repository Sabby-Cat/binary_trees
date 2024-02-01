#include "binary_trees.h"
/**
 * bst_insert - insert value in Binary Search Tree
 * @tree: double pointer to root node of BST
 * @value: value to store in inserted node
 * Return: pointer to created node or nullk
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *tmp = NULL;
	bst_t *sec = NULL;
	bst_t *ret = NULL;

	if (!tree)
		return (NULL);
	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));
	tmp = *tree;
	while (tmp)
	{
		sec = tmp;
		if (value < tmp->n)
			tmp = tmp->left;
		else if (value > tmp->n)
			tmp = tmp->right;
		else if (value == tmp->n)
			return (NULL);
	}
	ret = binary_tree_node(NULL, value);
	if (sec == NULL)
		sec = ret;
	else if (value < sec->n)
	{
		sec->left = ret;
		ret->parent = sec;
	}
	else
	{
		sec->right = ret;
		ret->parent = sec;
	}
	return (ret);
}
