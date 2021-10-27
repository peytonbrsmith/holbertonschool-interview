#include "binary_trees.h"
/**
 * sorted_array_to_avl - entry point for sorted array to avl conversion
 *
 * @array: sorted array to be converted
 * @size: size of array
 *
 * Return: the new tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (create_tree(array, 0, size - 1, NULL));
}
/**
 * create_tree - creates the new tree and recursively sets its leaves
 *
 * @array: sorted array to be converted
 * @start: start of the array (or sub-array)
 * @end: end of the array (or sub-array)
 * @root: root of the tree or subtree
 *
 * Return: the new tree or subtree
 */
avl_t *create_tree(int *array, int start, int end, avl_t *root)
{
	int mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;

	root = create_leaf(root, array[mid]);
	if (root == NULL)
		return (NULL);

	root->left = create_tree(array, start, mid - 1, root);
	root->right = create_tree(array, mid + 1, end, root);

	return (root);
}
/**
 * create_leaf - creates a new leaf
 *
 * @root: root of the tree or subtree
 * @value: value of the new leaf
 *
 * Return: the new leaf
 */
avl_t *create_leaf(avl_t *root, int value)
{
	avl_t *new_leaf = NULL;

	new_leaf = malloc(sizeof(avl_t));
	if (new_leaf == NULL)
		return (NULL);

	(new_leaf)->n = value;
	(new_leaf)->left = NULL;
	(new_leaf)->right = NULL;

	if (root == NULL)
	{
		new_leaf->parent = NULL;
		root = new_leaf;
	}
	else
		new_leaf->parent = root;

	return (new_leaf);
}
