#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if node is root
 *
 * @node: pointer
 *
 * Return: 1 if node is a root, otherwise 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	return (!(!node || node->parent));
}
