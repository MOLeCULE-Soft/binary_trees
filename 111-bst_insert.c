#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 *
 * @tree: pointer
 * @value: to be inserted
 *
 * Return: pointer inserted or NULL
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current, *new;

	if (tree)
	{
		current = *tree;
		if (!current)
		{
			new = binary_tree_node(current, value);
			return (new ? (*tree = new) : NULL);
		}
		if (value < current->n)
		{
			if (current->left)
				return (bst_insert(&current->left, value));
			new = binary_tree_node(current, value);
			return (new ? (current->left = new) : NULL);
		}
		if (value > current->n)
		{
			if (current->right)
				return (bst_insert(&current->right, value));
			new = binary_tree_node(current, value);
			return (new ? (current->right = new) : NULL);
		}
	}

	return (NULL);
}
