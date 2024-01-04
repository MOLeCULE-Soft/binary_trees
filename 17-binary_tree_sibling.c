#include "binary_trees.h"

/**
 * binary_tree_sibling - finds sibling node
 * @n: pointer
 *
 * Return: sibling otherwise, NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *n)
{
	if (!n || !n->parent)
		return (NULL);
	return (n->parent->left == n ? n->parent->right : n->parent->left);
}
