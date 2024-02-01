#include "binary_trees.h"
bst_t *min_valuue(bst_t *root);
/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to root node of tree to remove from
 * @value: value to remove
 * Return: pointer to new root node of tree after removal or null
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *sto = NULL;

	if (!root)
		return (NULL);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			sto = root->right;
			free(root);
			return (sto);
		}
		else if (!root->right)
		{
			sto = root->left;
			free(root);
			return (sto);
		}
		sto = min_valuue(root->right);
		root->n = sto->n;
		root->right = bst_remove(root->right, sto->n);
	}
	return (root);
}

/**
 * min_valuue - find smallest node of Binary Search Tree
 * @root: pointer to root node of tree
 * Return: pointer to smallest node
 */
bst_t *min_valuue(bst_t *root)
{
	bst_t *min = root;

	while (min->left)
		min = min->left;
	return (min);
}
