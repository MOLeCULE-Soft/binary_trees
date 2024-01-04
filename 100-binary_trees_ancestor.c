#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *
 * @first: pointer
 * @second: pointer
 *
 * Return: lowest common ancestor or NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *t1, *t2;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	t1 = first->parent, t2 = second->parent;
	if (first == t2 || !t1 || (!t1->parent && t2))
		return (binary_trees_ancestor(first, t2));
	else if (t1 == second || !t2 || (!t2->parent && t1))
		return (binary_trees_ancestor(t1, second));

	return (binary_trees_ancestor(t1, t2));
}
