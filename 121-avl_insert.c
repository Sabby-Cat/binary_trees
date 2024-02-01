#include "binary_trees.h"
avl_t *insert_a(avl_t **tree, int value);
/**
 * bst_insert - insert value in Binary Search Tree
 * @tree: double pointer to root node of BST
 * @value: value to store in node
 * Return: pointer to created node or null
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *tmp = *tree;
	bst_t *sec = NULL;
	bst_t *new = binary_tree_node(NULL, value);

	if (*tree == NULL)
		*tree = new;
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
	if (sec == NULL)
		sec = new;
	else if (value < sec->n)
	{
		sec->left = new;
		new->parent = sec;
	}
	else
	{
		sec->right = new;
		new->parent = sec;
	}
	return (new);
}

/**
 * insert_a - inserts a value in an AVL Tree
 * @tree: a double pointer to root node of AVL tree
 * @value: value to insert
 * Return: pointer to created node or null
 */
avl_t *insert_a(avl_t **tree, int value)
{
	int bal = 0;
	avl_t *node = bst_insert(tree, value);

	bal = binary_tree_balance(*tree);
	if (bal > 1 && value < node->left->n)
		return (binary_tree_rotate_right(node));
	if (bal < -1 && value > node->right->n)
		return (binary_tree_rotate_left(node));
	if (bal > 1 && value > node->left->n)
	{
		node->left = binary_tree_rotate_left(node->left);
		return (binary_tree_rotate_right(node));
	}
	if (bal < -1 && value < node->right->n)
	{
		node->right = binary_tree_rotate_right(node->right);
		return (binary_tree_rotate_left(node));
	}
	return (node);
}
