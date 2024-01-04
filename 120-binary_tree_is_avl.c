#include "binary_trees.h"

int binary_tree_is_avl(const binary_tree_t *);
int is_avl_helper(const binary_tree_t *, int, int);
size_t height(const binary_tree_t *);

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
 * is_avl_helper - is_avl_helper
 * @tree: pointer
 * @lo: smallest
 * @hi: largest
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t lhgt, rhgt, diff;

	if (tree)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		lhgt = height(tree->left);
		rhgt = height(tree->right);
		diff = lhgt > rhgt ? lhgt - rhgt : rhgt - lhgt;
		if (diff > 1)
			return (0);
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
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
