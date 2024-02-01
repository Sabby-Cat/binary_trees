#include "binary_trees.h"
size_t bt_size(const binary_tree_t *tree);
/**
 * heap_insert- Insert value in Max Binary Heap
 * @root: double pointer to root node of Heap to insert value
 * @value: value to store in node
 * Return: pointer to created node or NULL
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new, *oppo;
	int siz, leav, sub, bit, lev, tmp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	siz = bt_size(tree);
	leav = siz;
	for (lev = 0, sub = 1; leav >= sub; sub *= 2, lev++)
		leav -= sub;
	for (bit = 1 << (lev - 1); bit != 1; bit >>= 1)
		tree = leav & bit ? tree->right : tree->left;
	new = binary_tree_node(tree, value);
	leav & 1 ? (tree->right = new) : (tree->left = new);
	oppo = new;
	for (; oppo->parent && (oppo->n > oppo->parent->n); oppo = oppo->parent)
	{
		tmp = oppo->n;
		oppo->n = oppo->parent->n;
		oppo->parent->n = tmp;
		new = new->parent;
	}
	return (new);
}

/**
 * bt_size - Measures size of binary tree
 * @tree: pointer to tree to be measure
 * Return: Size of tree or 0
 */
size_t bt_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (bt_size(tree->left) + bt_size(tree->right) + 1);
}
