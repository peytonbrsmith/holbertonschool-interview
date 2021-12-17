#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * height - finds the height of the tree
 * @root: the root of the tree
 *
 * Return: the height of the tree
*/
int height(binary_tree_t *root)
{
	int right = 0, left = 0;

	if (root != NULL)
	{
		left = height(root->left);
		right = height(root->right);

		if (left > right)
			return (left + 1);
		else
			return (right + 1);
	}
	return (0);
}

/**
 * heapify - create heap out of binary tree
 * @root: root of binary tree
 */
void heapify(heap_t *root)
{
	heap_t *max;
	int val;

	if (root->left != NULL && root->right != NULL)
	{
		max = root->left;
		if (root->right && root->right->n > max->n)
			max = root->right;
		if (max->n > root->n)
		{
			val = root->n;
			root->n = max->n;
			max->n = val;
			heapify(max);
		}
	}
}

/**
 * find_last - find the last node of the tree
 * @root: root of tree
 *
 * Return: The last node
 */
heap_t *find_last(heap_t *root)
{
	int height_l = 0, height_r = 0;

	if (root->left == NULL && root->right == NULL)
		return (root);
	if (root->left)
		height_l = height(root->left);
	if (root->right)
		height_r = height(root->right);
	if (height_l == height_r)
		return (find_last(root->right));
	return (find_last(root->left));
}

/**
 * heap_extract - Extracts root node of a max heap and rebuilds
 * @root: root node of the heap
 *
 * Return: return the value extracted
 */
int heap_extract(heap_t **root)
{
	int val = 0;
	heap_t *temp;

	if (*root != NULL || root != NULL)
	{
		val = (*root)->n;

		if ((*root)->left == NULL)
		{
			free(*root);
			*root = NULL;
			return (val);
		}

		temp = find_last(*root);
		(*root)->n = temp->n;

		if (temp->parent->right == temp)
			temp->parent->right = NULL;
		else
			temp->parent->left = NULL;

		heapify(*root);
		free(temp);
	}
	return (val);
}
