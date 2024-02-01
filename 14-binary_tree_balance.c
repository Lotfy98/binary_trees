#include "binary_trees.h"

/**
 * binary_tree_heigh - Measures the height of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: 0 if tree is NULL.
 */
size_t binary_tree_heigh(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t west , east = 0;

		west = tree->left ? 1 +binary_tree_heigh(tree->left) : 1;
		east = tree->right ? 1 + binary_tree_heigh(tree->right) :1;

		return ((west > east) ? west : east);
	}
	return (0);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: 0 if tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_heigh(tree->left) - binary_tree_heigh(tree->right));
	return (0);
}
