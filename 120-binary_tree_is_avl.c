#include "binary_trees.h"

int is_avl_helper(const binary_tree_t *, int, int);
int binary_tree_is_avl(const binary_tree_t *);
size_t height(const binary_tree_t *);

/**
 * is_avl_helper - is_avl_helper
 * @tree: pointer
 * @lo: smallest
 * @hi: largest
 *
 * Return: 1 or 0
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t l_height, r_height, diff;

	if (tree)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		l_height = height(tree->left);
		r_height = height(tree->right);
		diff = l_height > r_height ? l_height - r_height : r_height - l_height;
		if (diff > 1)
			return (0);
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_avl - binary_tree_is_avl
 *
 * @tree: pointer
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	return (tree ? is_avl_helper(tree, INT_MIN, INT_MAX) : 0);
}

/**
 * height - height
 * @tree: pointer
 *
 * Return: height or 0
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + height(tree->left) : 1;
		r = tree->right ? 1 + height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}
