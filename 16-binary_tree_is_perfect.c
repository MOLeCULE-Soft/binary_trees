#include "binary_trees.h"

int binary_tree_is_perfect(const binary_tree_t *);
int is_perfect_recursive(const binary_tree_t *, size_t, size_t);
const binary_tree_t *get_leaf(const binary_tree_t *);
size_t depth(const binary_tree_t *);
unsigned char is_leaf(const binary_tree_t *);

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: pointer
 *
 * Return: 0 if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}

/**
 * depth - returns the depth of node in a binary tree
 * @tree: pointer
 *
 * Return: The depth of node
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf - Returns a leaf of a binary tree.
 * @tree: pointer
 *
 * Return: pointer to the first leaf encountered
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_recursive - checks if a binary tree is perfect recursively
 * @tree: pointer
 * @leaf_depth: depth of one leaf in binary tree
 * @level: current node level
 *
 * Return: ff the tree is perfect, 1, otherwise 0
 */
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (!tree->left || !tree->right)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
		is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * is_leaf - Checks if a node is a leaf of a binary tree.
 * @node: A pointer to the node to check.
 *
 * Return: If the node is a leaf, 1, otherwise, 0.
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((!node->left && !node->right) ? 1 : 0);
}
