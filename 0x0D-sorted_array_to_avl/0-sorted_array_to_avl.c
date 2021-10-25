#include "binary_trees.h"

avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (array == NULL || size == 0)
        return (NULL);

    return create_tree(array, 0, size - 1, NULL);
}

avl_t *create_tree(int *array, int start, int end, avl_t *root)
{
    int mid;

    if (start > end)
        return NULL;

    //Compute the middle index and make it as root.
    mid = (start + end)/2;
    root = create_leaf(root, array[mid]);

    //Recursively create left and right subtrees.
    root->left = create_tree(array, start, mid - 1, root);
    root->right = create_tree(array, mid + 1, end, root);
    return root;
}

avl_t *create_leaf(avl_t *root, int value)
{
    avl_t *new_leaf;

    new_leaf = malloc(sizeof(avl_t));
    if (new_leaf == NULL)
        return (NULL);

    (new_leaf)->n = value;
    (new_leaf)->left = NULL;
    (new_leaf)->right = NULL;

    if (root == NULL)
        root = new_leaf;
    else
        new_leaf->parent = root;

    return (new_leaf);
}
