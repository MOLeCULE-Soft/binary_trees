#include "binary_trees.h"

bst_t *bst_remove(bst_t *root, int value);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *inorder_successor(bst_t *root);

/**
 * bst_remove - bst_remove
 *
 * @root: pointer
 * @value: to be removed
 *
 * Return: A pointer to the new root node of the tree after removing
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}

/**
 * bst_remove_recursive - bst_remove_recursive
 * @root: pointer
 * @node: pointer
 * @value: to be removed
 *
 * Return: A pointer to the root node after deletion
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_delete - bst_remove_recursive
 * @root: pointer
 * @node: pointer
 *
 * Return: A pointer to the new root node after deletion
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	if (!node->left)
	{
		if (parent && parent->left == node)
			parent->left = node->right;
		else if (parent)
			parent->right = node->right;
		if (node->right)
			node->right->parent = parent;
		free(node);
		return (!parent ? node->right : root);
	}

	if (node->right == NULL)
	{
		if (parent && parent->left == node)
			parent->left = node->left;
		else if (parent)
			parent->right = node->left;
		if (node->left)
			node->left->parent = parent;
		free(node);
		return (!parent ? node->left : root);
	}

	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (bst_delete(root, successor));
}

/**
 * inorder_successor - inorder_successor
 * @root: pointer
 *
 * Return: The minimum value in tree
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left)
		root = root->left;
	return (root);
}
