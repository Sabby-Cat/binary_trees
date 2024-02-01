#include "binary_trees.h"
bst_t *bst_remove(bst_t *root, int value);
int remove_type(bst_t *root);
int sucsesor(bst_t *node);
void balan(avl_t **tree);
/**
 * avl_remove - Remove node from an AVL tree
 * @root: pointer to root node
 * @value: value to remove in tree
 * Return: pointer to new root node
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	balan(&root_a);
	return (root_a);
}

/**
 * bst_remove - Remove node from BST tree
 * @root: Root of tree
 * @value: Node with this value to remove
 * Return: tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int tp = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		tp = remove_type(root);
		if (tp != 0)
			bst_remove(root->right, tp);
	}
	else
		return (NULL);
	return (root);
}

/**
 * remove_type - Function that removes node depending of its children
 * @root: Node to remove
 * Return: 0 if it has no children or other value if it has
 */
int remove_type(bst_t *root)
{
	int new = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new = sucsesor(root->right);
		root->n = new;
		return (new);
	}
}

/**
 * sucsesor - Get next sucsesor i mean min node in right subtree
 * @node: Tree to check
 * Return: min value of tree
 */
int sucsesor(bst_t *node)
{
	int l = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		l = sucsesor(node->left);
		if (left == 0)
			return (node->n);
		return (l);
	}
}

/**
 * balan - Measure balance factor of AVL
 * @tree: Tree to go through
 * Return: Balanced factor
 */
void balan(avl_t **tree)
{
	int bal_v;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	balan(&(*tree)->left);
	balan(&(*tree)->right);
	bal_v = binary_tree_balance((const binary_tree_t *)*tree);
	if (bal_v > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bal_v < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
