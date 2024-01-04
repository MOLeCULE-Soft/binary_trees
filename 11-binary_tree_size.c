#include "binary_trees.h"

/**
 * binary_tree_size - measures binary tree size
 *
 * @tree: pointer
 *
 * Return: 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 1;

	if (tree)
	{
		size += binary_tree_size(tree->left);
		size += binary_tree_size(tree->right);
	}

	return (--size);
}
