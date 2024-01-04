#include "binary_trees.h"

/**
 * binary_tree_uncle - finds node uncle
 * @n: pointer
 *
 * Return: NULL if node is NULL or node has no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *n)
{
	bool a, b;

	a = !n || !n->parent || !n->parent->parent;
	b = n->parent->parent->left == n->parent;
	return (a ? NULL : b ? n->parent->parent->right : n->parent->parent->left);
}
