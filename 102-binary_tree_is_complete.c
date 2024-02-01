#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the binary tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    int flag = 0;
    size_t size = 0;
    binary_tree_t **queue;

    if (tree == NULL)
        return (0);

    queue = malloc(sizeof(binary_tree_t *) * (size + 1));
    if (queue == NULL)
        return (0);

    queue[size++] = (binary_tree_t *)tree;

    while (size > 0)
    {
        binary_tree_t *node = queue[0];
        size_t i;

        for (i = 0; i < size - 1; i++)
            queue[i] = queue[i + 1];

        size--;

        if (node->left != NULL)
        {
            if (flag == 1)
            {
                free(queue);
                return (0);
            }
            queue[size++] = node->left;
        }
        else
            flag = 1;

        if (node->right != NULL)
        {
            if (flag == 1)
            {
                free(queue);
                return (0);
            }
            queue[size++] = node->right;
        }
        else
            flag = 1;
    }

    free(queue);
    return (1);
}
