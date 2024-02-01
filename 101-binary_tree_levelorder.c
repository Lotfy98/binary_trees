#include "binary_trees.h"

/**
 * binary_tree_levelorder - goes through a binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    binary_tree_t **queue;
    size_t front = 0, rear = 0, size = 1;

    if (tree == NULL || func == NULL)
        return;

    queue = malloc(sizeof(binary_tree_t *) * size);
    if (queue == NULL)
        return;

    queue[rear] = (binary_tree_t *)tree;

    while (front < size)
    {
        binary_tree_t *node = queue[front++];

        func(node->n);

        if (node->left != NULL)
        {
            if (rear + 1 >= size)
            {
                size *= 2;
                queue = realloc(queue, sizeof(binary_tree_t *) * size);
                if (queue == NULL)
                    return;
            }
            queue[++rear] = node->left;
        }

        if (node->right != NULL)
        {
            if (rear + 1 >= size)
            {
                size *= 2;
                queue = realloc(queue, sizeof(binary_tree_t *) * size);
                if (queue == NULL)
                    return;
            }
            queue[++rear] = node->right;
        }
    }

    free(queue);
}
