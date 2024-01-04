#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts node as left-child another node
 *
 * @parent: pointer to parent node
 * @value: value of new node
 *
 * Return: pointer to created node otherwise, NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new)
	{
		if (parent->left != NULL)
		{
			new->left = parent->left;
			parent->left->parent = new;
		}
		parent->left = new;
	}
	return (new);
}
