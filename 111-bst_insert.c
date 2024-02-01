#include "binary_trees.h"
/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *parent;

	if (tree == NULL)
		return (NULL);

	parent = NULL;
	while (*tree != NULL)
	{
		if (value == (*tree)->n)
			return (NULL);

		parent = *tree;
		if (value < (*tree)->n)
			tree = &(*tree)->left;
		else
			tree = &(*tree)->right;
	}

	*binary_tree_node(parent, value);

	if (parent == NULL)
		*tree = new_node;
	else if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (new_node);
}
