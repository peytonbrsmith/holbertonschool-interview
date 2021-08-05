#include "binary_trees.h"

/**
  * binary_tree_node - Create a new binary tree node
  * @parent: Parent node
  * @value: the value of the node
  *
  * Return: A newly created binary tree node
  */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;

	if (parent == NULL)
	{
		new_node->parent = NULL;
		parent = new_node;
		return (new_node);
	}
	else if (parent->left == NULL)
	{
		new_node->parent = parent;
		parent->left = new_node;
		return (new_node);
	}
	else if (parent->right == NULL)
	{
		new_node->parent = parent;
		parent->right = new_node;
		return (new_node);
	}
	else
	{
		free(new_node);
		return (NULL);
	}
}
