#include "binary_trees.h"

int binary_tree_is_full(const binary_tree_t *tree);
int is_full_recursive(const binary_tree_t *tree);

/**
 * binary_tree_is_full - checks if binary tree is full
 *
 * @tree: pointer
 *
 * Return: 0 if tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_full_recursive(tree));
}

/**
 * is_full_recursive - checks if a binary tree is full recursively
 *
 * @tree: pointer
 *
 * Return: 0 if tree is not NULL, otherwise 1
 */
int is_full_recursive(const binary_tree_t *tree)
{
	if (tree)
	{
		if ((tree->left && !tree->right) ||
		    (!tree->left && tree->right) ||
		    is_full_recursive(tree->left) == 0 ||
		    is_full_recursive(tree->right) == 0)
			return (0);
	}

	return (1);
}
