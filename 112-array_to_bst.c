#include "binary_trees.h"

/**
 * array_to_bst - array_to_bst
 *
 * @array: pointer
 * @size: of array
 *
 * Return: pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i, j;

	if (!array)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
			if (array[j] == array[i])
				break;
		if (j == i)
			if (!bst_insert(&tree, array[i]))
				return (NULL);
	}

	return (tree);
}
