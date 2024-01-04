#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts node as right-child another node
 *
 * @parent: pointer to parent node
 * @value: value of new node
 *
 * Return: pointer to created node otherwise, NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new)
	{
		if (parent->right)
		{
			new->right = parent->right;
			parent->right->parent = new;
		}
		parent->right = new;
	}
	return (new);
}
